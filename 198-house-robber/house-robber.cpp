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
        vector<int>dp(n,-1);
        int ans =solve(n-1,nums,dp);
        return ans;
    }
};