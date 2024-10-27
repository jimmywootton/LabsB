#include "minFunc.h"
const int * min(const int arr[], int arrSize) 
{
    if (arrSize == 0)
    {
        return nullptr;
    }
    if (arrSize == 1)
    {
        return arr;
    }
    const int* minimum = min(arr, arrSize - 1);
    if (*minimum < arr[arrSize - 1]) 
    {
        return minimum;
    } 
    else 
    {
        const int* index = arr -1 + arrSize ;
        return index;
    }

}