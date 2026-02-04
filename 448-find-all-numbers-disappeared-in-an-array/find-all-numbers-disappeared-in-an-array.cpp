class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res;
        int i=0;
        while(i<nums.size()){
            if(nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1])swap(nums[i],nums[nums[i]-1]);
            else{
                i++;
            }
            
        }
        int k;
        for(k=0;k<nums.size();k++){
            if(nums[k]-1!=k)res.push_back(k+1);
        }
        return res;
    }
};