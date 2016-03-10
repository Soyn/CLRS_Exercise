#include <iostream>

// @Author: Soyn
// @Brief: the implement of insert sort. More details please go to Wiki.
// @Param int_array: the input array
// @Param sz: the input array's size
// @CreatedTime: 10/3/16.
void InsertSort(int *int_array, size_t sz)
{
    for(auto unsorted_start = 1; unsorted_start < sz; ++unsorted_start){
        int key = int_array[unsorted_start];
        auto sorted_end = unsorted_start - 1;
        for(; sorted_end >= 0 &&(int_array[sorted_end] > key); --sorted_end){
                int_array[sorted_end + 1] = int_array[sorted_end];
        }
        int_array[sorted_end + 1] = key;
    }

}

int main(int argc, char **argv)
{
    return 0;
}
