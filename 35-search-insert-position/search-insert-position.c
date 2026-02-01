int searchInsert(int* nums, int numsSize, int target)
{
    int h=numsSize-1,l=0,m;
    while(l<=h)
    {
        m=((l+h)/2);
        if(target==nums[m])
        {
            return m;
        }
        else if(target<nums[m])
         {
            h=m-1;}
        else
        {
            l=m+1;
        }
    }
    return l;
}