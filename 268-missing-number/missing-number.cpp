class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i)i++;
            else{
                if(nums[i]>nums.size()-1)i++;
                else{
                    swap(nums[i],nums[nums[i]]);
                }
            }
        }
        int k;
        for(k=0;k<nums.size();k++){
            if(nums[k]!=k)return k;
        }
        return k;
    }
};