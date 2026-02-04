class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;
        int i=0;
        while(i<nums.size()){
            int c=nums[i]-1;
            if(nums[i]-1!=i){
                if(nums[i]!=nums[c])swap(nums[i],nums[c]);
                else i++;
            }
            else i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1!=i){
                res.push_back(nums[i]);
                res.push_back(i+1);
            }
        }
        return res;
    }
};