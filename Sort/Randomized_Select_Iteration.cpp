#include <iostream>
#include <stdlib.h>
//!
//! Randomized_Select algorithm using iteration
//! Created by Sony. 2/8/15.
//!

void Print( int *a)
{
    size_t Size = sizeof(a) / a[0];
    for( int i = 0; i < Size; ++i)
        std :: cout << a[i] << " , ";
    std :: cout << std :: endl;
}
void EXCHANGE(int &lhs, int &rhs)
{
    int tmp;
    tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int Partion(int *a, size_t p, size_t r)
{
    int pivot;
    size_t i,j;
    pivot = a[p];
    for( i = p, j = p + 1; j < r; ++j){
        if( a[j] < pivot){
            ++i;
            EXCHANGE(a[i],a[j]);
        }
    }
    EXCHANGE(a[i],a[p]);
    return i;
}

int Randomized_Partion(int *a, size_t p, size_t r)
{
    int i = rand() % (r - p) + p ;
    EXCHANGE(a[i],a[p]);
    return Partion(a,p,r);
}
int Randomized_Select(int *a, size_t p, size_t r, size_t i)
{
    while( p < r)
    {
        int pos = Randomized_Partion(a, p, r);
        int k =  pos - p + 1;
        if( i == k){
            return a[pos];
        }else if ( i < k){
            r = pos;
        }else {
            p = pos + 1;
            i = i - k ;
        }
    }
    return -1;
}
int main(void)
{
    int a[] = {2,1,3,4,1,8,9,6,7};
    int elem = Randomized_Select(a,0,sizeof(a)/sizeof(a[0]),6);
    if( elem != -1){
        std :: cout << "The selected number is: " << elem << std :: endl;
    } else{
        std :: cout << "There is no such a number!" << std :: endl;
    }
    return 0;
}
