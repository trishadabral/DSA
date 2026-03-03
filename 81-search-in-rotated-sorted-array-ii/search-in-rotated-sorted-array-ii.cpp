class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,m;
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]==target)return true;
            else if(nums[m] == nums[l] && nums[m] == nums[h]){
                l++;h--;
            }
            else if(nums[m]>=nums[l]){
                if(nums[l]<=target && target<=nums[m]) h=m-1;
                else l=m+1;
            }    
            else {
                if(nums[m]<=target && target<=nums[h]) l=m+1;
                else h=m-1;
            }    
        }
        return false;
    }
};