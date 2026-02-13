class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,n=nums.size(),m=0;
        for(int i=0;i<n;i++){
            if(nums[i])c++;
            else{
                m=max(m,c);
                c=0;
            }    
        }
        if(m<c)m=c;
        return m;
    }
};