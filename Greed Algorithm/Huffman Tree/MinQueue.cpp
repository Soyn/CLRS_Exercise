#include "MinQueue.h"
#include <iostream>
/*********************
*
* Minimum Queue implement.
* Created Time: 30/1/16.
* Ahthor: Soyn.
*
*/

///
///<summary>Return the left child subscript.</summary>
///
int MinQueue :: LEFT(const int i)
{
   return 2 * i;
}
int MinQueue :: RIGHT(const int i)
{
    return 2 * i + 1;
}

int MinQueue :: CalculateHeapSize()
{
    return vec.size() - 1; //drop the -1(vec[0]) from the vec.
}
MinQueue :: MinQueue(node *elem, size_t Size)
{
    vec.push_back(t);
    for(size_t i = 0; i < Size; ++i){
        vec.push_back(elem[i]);
        elem[i].left = elem[i].right = NULL;
    }

    HeapSize = CalculateHeapSize();
}

void MinQueue :: Exchange(int i, int j)
{
    node tmp;
    /// initialize the tmp
    tmp.alpha = vec[i].alpha;
    tmp.frequence = vec[i].frequence;

    /// exchange vec[i] and vec[j]
    vec[i].alpha = vec[j].alpha;
    vec[i].frequence = vec[j].frequence;
    vec[j].alpha = tmp.alpha;
    vec[j].frequence = tmp.frequence;
}

void MinQueue :: MinHeapify(int index)
{
    int l,r,least;
    l = LEFT(index);
    r = RIGHT(index);

    if( (l <= HeapSize) && (vec[l].frequence) < vec[index].frequence)
        least = l;
    else
        least = index;

    if( (r <= HeapSize ) && ( vec[r].frequence < vec[least].frequence))
        least = r;

    if(least != index){ // if least changed, the properity of minimum heap may not satisfy.
        Exchange(least,index);
        MinHeapify(least);
        }
}

void MinQueue :: Print(){
    for(const auto e : vec){
        if(e.frequence != -1)
            std :: cout << e.frequence << ' ';
        }
    std :: cout << std :: endl;
    std :: cout << "HeapSize: " << HeapSize << std :: endl;
}

void MinQueue :: BuildMinHeap()
{
    for(int i = HeapSize / 2; i > 0; --i){
        MinHeapify(i);
    }
}

node MinQueue :: HeapMinimum()
{
    return vec[1];
}

node MinQueue :: HeapExtractMin()
{
    if( HeapSize < 1){
        std :: cerr << "Heap underflow" << std :: endl;
        return vec[0];
        }
    node Min(vec[1]);
    vec[1] = vec[HeapSize];
    vec.erase(vec.end() - 1); //erase the end element.
    HeapSize = CalculateHeapSize(); // update the heap size.
    BuildMinHeap(); // to adjust the heap to keep the properity.
    return Min;
}

///
/// <summary> update the specified node in the heap. </summary>
/// <para name = "index"> the specified node.</para name>
/// <para name = "key"> the node will replace the vec[index]</para name>
///

void MinQueue :: HeapDecreaseKey(int index, node &key)
{
    if(key.frequence > vec[index].frequence){
        std :: cerr << "new key is lager than current key." << std :: endl;
        return ;
    }

    vec[index].frequence = key.frequence;
    vec[index].alpha = key.alpha;

    while((index > 1) && (vec[PARENT(index)].frequence > vec[index].frequence)){

        Exchange(index,PARENT(index));
        index = PARENT(index);
    }
}

int MinQueue :: PARENT(const int index)
{
    return index / 2;
}

void MinQueue :: MinHeapInsert(node &val)
{
    vec.push_back(val);
    HeapSize = CalculateHeapSize();
    HeapDecreaseKey(HeapSize,val);
}
