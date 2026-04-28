class Solution {
public:
    int solve(int idx,vector<int>&arr,vector<int>&dp){
        if(idx<0)return 0;
        if(idx==0)return arr[idx];
        if(dp[idx]!=-1)return dp[idx];
        int pick=arr[idx]+solve(idx-2,arr,dp);
        int npick=solve(idx-1,arr,dp);
        return dp[idx]=max(pick,npick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp,temp1;
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp.push_back(nums[i]);
        }
        return max(solve(temp.size()-1, temp, dp),
           solve(temp1.size()-1, temp1, dp1));
    }
};