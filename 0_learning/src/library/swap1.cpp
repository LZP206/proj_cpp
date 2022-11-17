#include "swap.h"

//值传递
void swap1(int p1 ,int p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}