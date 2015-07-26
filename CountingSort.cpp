#include <iostream>


const int N = 8;

using namespace std;
int getTmpSize( int *a)
{
    int MaxValue = a[0];
    for( int i = 1;i < N; ++i)
            a[i] > MaxValue ? MaxValue = a[i] : MaxValue;
    return MaxValue + 1;
}

void print( int *a, int n){
    for( int i = 0; i < n; ++i)
         cout << a[i] << " " ;
    cout << endl;
}
void CountingSort( int *a, int *b, int k)
{
    int c[k];
    for( int i = 0; i < k; ++i)
        c[i] = 0;

    for( int i = 0; i < N; ++i)
        ++c[ a[i] ];

    for( int i = 1; i < k; ++i)
        c[i] = c[i] + c[ i -1];


    for( int i = N -1; i >= 0; --i){
        b[ c[a[i]] - 1] = a[i];
        --c[a[i]];
    }

    print(b, N);

}
int main(void)
{
    int a[N] = {2,5,3,0,2,3,0,3}, b[N] = {-1};
    int k = getTmpSize(a);
    CountingSort(a,b,k);
    return 0;
}
