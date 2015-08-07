[英文原文地址](http://www.eventhelix.com/RealtimeMantra/HeaderFileIncludePatterns.htm#.VcOFPPmqruB)
在开发大型的软件项目时，头文件需要得到恰当的管理，甚至在c中也会面临这种问题，当我们用
c++开发时，头文件的管理会变得更复杂，更加耗费我们的时间去管理，下面我将讲一些包含规则来简化这个苦差事。

##头文件包含规则

- 当在在当前正在编写的文件中没有预先相应的声明时我们需要include我们需要的头文件，否则我们需要声明。
- 头文件应该设计的与include的顺序无关.
   - 例如在写x.cpp时尽量确保x.h是x.cpp需要的第一个header file.
- header file的包含机制允许包含重复的头文件.

接下来我们用一下例子来说明这些规则：

##包含头文件范例：

下面的例子阐明了几种不同类型的依赖关系，假设我们有一个类A声明并定义在 `a.h` 和 `a.cpp`中.

`a.h`

```cpp

    #ifndef _a_h_included_
    #define _a__h_included_
    #include "ABase.h"
    #include "b.h"
    //预先声明需要的类
    class C;
    class D;
    
    class A : public ABase
    {
        B m_b;
        C *m_c;
        D *m_d;
     public:
        void SetC(C *c);
        C *GetC() const;
        
        void ModifyD(D*d);
    }
    #endif
    
```

`a.cpp`


```cpp
    #include "a.h"
    #include "d.h"
    
    void A :: SetC(C*c)
    {
        m_c = c;
    }
    
    C *A :: GetC() const
    {
        return m_c;
    }
    
    void A :: ModifyD(D *d)
    {
        d -> SetX(0);
        d ->SetY(0);
        m_d = d;
    }

```

##对头文件包含过程的分析

<talble class = "table table-bordered table-striped table-condensed">
    <tr>
        <td>**class Bbase**</td>
        <td> ABase是基类，需要被A继承，因此Abase需要完成的声明，编译器需要知道ABase的大小才能确定类A的大小，所以在a.h中应当显式地包含ABase.h</td>
    </tr>
    <tr>
        <td>**class B**</td>
        <td>类B的对象是类A的数据成员,因此类B也需要完整的声明，因为编译器在确定类A对象大小时需要知道类B对象的大小，因此类B也需要显式地包含</td>
    </tr>
    <tr>
        <td>**class C** </td>
        <td>类c在类A中是以指针类型出现的,在这里a.h或者a.cpp对类c内容的大小不关心,这时候一个前置的类c声明放在a.h中就可以了，在上面a.h和a.cpp中也并没有显式的包含c.h</td>
    </tr>
    <tr>
        <td>**class D**</td>
        <td>类D和类c一样也是作为指针在a.h中出现，所以也只需要在a.h中做前置的声明，但是在a.cpp中用了类D的对象，所以在a.cpp中需要显示的包含d.h</td>
    </tr>
</table>

##关键点

- 当需要类的实例参与程序的设计时我们需要显示的包含相应的头文件，但如果是指针我们可以使用前置声明。
- 在a.cpp中a.h是第一个被包含的头文件，a.h不希望有其他的头文件包含在它前面，由于a.h在a.cpp中作为了第一个包含的头文件，为了程序的正确编译，我们不允许有其他任何的头文件在a.h以前被包含。
    - 如果在所有的类中都遵循这个规则（换句话说就是x.cpp总是将x.h作为第一个包含的头文件），那么将不会产生各个头文件包含的依赖关系。
- 在a.h中的预处理过程（_a_h_include_）,允许头文件的重复包含。

##循环依赖

下面的class X 和 class Y存在循环依赖， 我们通过前置声明来解决这个问题

```cpp
    /*=======x.h===========*/
    class Y;
    
    class X
    {
        Y *m_y;
        .....
    };
    /*=====y.h============*/
    class X;
    class Y
    {
        X *m_x;
        .......
    };
```