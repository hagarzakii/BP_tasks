int singleNumber(int* nums, int numsSize){
    int found = 0 ;
    int element;
    for(int i = 0 ; i < numsSize ; i++)
    {
        for(int j = 0 ; j < numsSize ; j++)
            {
                if(nums[i] == nums[j])
                {
                    found++;
                }
            }
        if(found == 1)
        {
            element = nums[i];
            goto exit_loops;
        }
        else
        {
            found = 0 ;
        }
    }
    exit_loops:
    return element ;
}