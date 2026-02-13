class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1)return;
        int i=j+1;
        while(i<n){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            else i++;
        }
    }
};