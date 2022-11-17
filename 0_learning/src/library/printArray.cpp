#include "sort_print_Array.h"

//打印数组函数
void printArray(int * arr, int len)  //int * arr 也可以写为int arr[]
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
