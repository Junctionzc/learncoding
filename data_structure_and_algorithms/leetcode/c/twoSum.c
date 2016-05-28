/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *retList = (int *)malloc(sizeof(int) * 2);
    int i, j;
    
    for (i = 0; i < numsSize - 1; ++i) {
        for (j = i; j < numsSize - 1; ++j) {
            if (nums[i] + nums[j + 1] == target) {
                retList[0] = i;
                retList[1] = j + 1;
                return retList;
            }       
        }
    }
    return retList;
}