class Solution {
public:
    int findMin(vector<int>& nums) {
         int l=0,h=nums.size()-1,m;
         //answer will bw i the unsorted part;
        while(l<h){
            m=l+(h-l)/2;
            if(nums[m]>nums[h]){//left part sorted
                l=m+1;
            }
            else if(nums[m]<nums[h]){//right part sorted 
                h=m;
            }
            else h--;//duplicate
        }
        return nums[l];
    }
};