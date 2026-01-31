class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[i],nums[m]);
                i++;
                m++;
            }
            else if(nums[m]==2){
                swap(nums[m],nums[h]);
                h--;
            }
            else{
                m++;
            }
            
        }
        for(int x:nums)cout<<x;
    }
};