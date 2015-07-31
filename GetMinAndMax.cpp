#include <iostream>
#include <initializer_list>
//!
//! @Brief:get the minmum and maxmum in one through.
//! Create by Soyn. 31/7/15.
//!

bool IsOdd( size_t n)
{
    return n % 2 ;
}
std::initializer_list<int> getLargerAndSmaller( int a, int b)
{
    if(a <= b){
        return {a,b};
    }else{
        return {b,a};
    }
}

int main(void)
{
    int  Min, Max;
    int a[] = {5,4,1,7,3,8,3,4,9,10};
    int n = sizeof(a) / sizeof(a[0]);
    for( int i = 0; i < n - 1; i += 2){
        if( (i ==0) &&IsOdd(n)){           // initialize the Min and Max.
            Min = Max = a[i];
        } else{
                auto item = getLargerAndSmaller(a[i],a[i+1]);
                if(i == 0){
                        Min = *(item.begin());
                        Max = *(item.begin() + 1);
                    }else{
                    Min > *(item.begin()) ? Min = *(item.begin()) : Min;
                    Max < *(item.begin() + 1) ? Max = *(item.begin() + 1) : Max;
                    }
        }
    }
           std :: cout << "Min: " << Min << " , " << "Max: " << Max << std :: endl;
     return 0;
}
