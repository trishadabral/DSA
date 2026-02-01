class Solution {
public:
    int search(vector<int>& nums, int target) {
         int h=nums.size()-1,l=0,m;
         while(l<=h){
            m=l+(h-l)/2;
            if(target==nums[m])return m;
            else if(nums[m]>=nums[l]){
                if(nums[l]<=target && target<=nums[m]) h=m-1;
                else l=m+1;
            }    
            else {
                if(nums[m]<=target && target<=nums[h]) l=m+1;
                else h=m-1;
            }    
         }
         return -1;
    }
};