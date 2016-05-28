#include <stdio.h>
#include <stdlib.h>
#include "twoSum.c"

int main()
{
    int nums[] = {0, 4, 3, 0};
    int *retList = NULL;
    
    retList = twoSum(nums, 4, 0);
    
    printf("[%d, %d]\n", retList[0], retList[1]);
    
    free(retList);
}