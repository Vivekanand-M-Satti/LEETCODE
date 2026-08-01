

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maximumProduct(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    long candidate1 = (long)nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    long candidate2 = (long)nums[0] * nums[1] * nums[numsSize - 1];

    return (int)(candidate1 > candidate2 ? candidate1 : candidate2);
}