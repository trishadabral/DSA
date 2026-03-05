class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1,sm=INT_MAX,m;
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]>=nums[l]){//left part sorted
                sm=min(sm,nums[l]);
                l=m+1;
            }
            else{//right part sorted 
                sm=min(nums[m],sm);
                h=m-1;
            }
        }
        return sm;
    }
};