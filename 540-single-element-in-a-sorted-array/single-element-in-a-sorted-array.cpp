class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=1,h=nums.size()-2,m;
        if(nums.size()==1 || nums[0]!=nums[1])return nums[0];
        if(nums[h]!=nums[nums.size()-1])return nums[nums.size()-1];
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]!=nums[m-1]&& nums[m]!=nums[m+1] )return nums[m];
            else if(m%2==1 && nums[m]==nums[m-1] || m%2==0 && nums[m]==nums[m+1])l=m+1;
            else h=m-1;
        }
        return nums[m];
    }
};