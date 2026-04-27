class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return n;
        // if element is less than 3 so no need to rearrange
        int j=2;
        for(int i=2;i<n;i++){
            if(nums[i]!=nums[j-2]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};