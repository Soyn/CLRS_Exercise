#include <iostream>

// @Author: Soyn
// @Brief: Swap two value.
// @Param a, b: the value to swap.
// @CreatedTime: 10/3/16.
void Swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// @Brief: select sort implement.
// @Note: More details go to Wiki.
// @Param int_array: the array
// @Param sz: array size
// @CreatedTime: 10/3/16.
void SelectSort(int *int_array, size_t sz)
{
    for(auto i = 0; i < sz; ++i){
        int current_minimum_subscript = i;
        for(auto j = i + 1; j < sz; ++j){
            if(int_array[current_minimum_subscript] > int_array[j]){
                current_minimum_subscript = j;
            }
        }
        if(current_minimum_subscript != i){
            Swap(int_array[i], int_array[current_minimum_subscript]);
        }
    }
}
int main(int argc, char **argv)
{
    return 0;
}
