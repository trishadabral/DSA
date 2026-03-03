class Solution {
public:
    int firstocc(vector<int>& nums, int target){
        int l=0,h=nums.size()-1,ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==target){ans=m; h=m-1;}
            else if(nums[m]<target) l=m+1;
            else h=m-1;
        }
        return ans;
    }

    int lastocc(vector<int>& nums, int target){
        int l=0,h=nums.size()-1,ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==target){ans=m; l=m+1;}
            else if(nums[m]<target) l=m+1;
            else h=m-1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target){
        return {firstocc(nums,target), lastocc(nums,target)};
    }
};