int removeElement(int* nums, int numsSize, int val) {

// inr *p2
int k=0;
    for (int i=0;i<numsSize;i++)
    {
        #if 1
        if(nums[i]==val)
        {
            for(int k=i;k<numsSize-1;k++)
            {
                nums[k]=nums[k+1];
            }
            i--;
            numsSize--;
           
        }
        #endif
         
    }
    return numsSize;
    
}