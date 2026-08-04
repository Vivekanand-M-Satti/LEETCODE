/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) 
{
  int  mama(const void*a,const void*b)
    {
        return *(int*)a-*(int*)b;
    }
    qsort(nums,numsSize,4,mama);
   int *arr = malloc((nums[numsSize-1] - nums[0]) * sizeof(int));

int j = 0;
int k = 0;

for (int x = nums[0]; x <= nums[numsSize-1]; x++) {
    if (k < numsSize && nums[k] == x) {
        k++;
    } else {
        arr[j++] = x;
    }
}

*returnSize = j;
return arr;
    
}