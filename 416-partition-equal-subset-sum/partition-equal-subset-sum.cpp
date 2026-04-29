class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int x:nums)sum+=x;
        if(sum%2==1)return false;
        sum=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
       //base condition 
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0] <=sum)dp[0][nums[0]] = true;
        //dp fill
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool take=false;
                if(nums[i]<target)take=dp[i-1][target-nums[i]];
                bool ntake=dp[i-1][target];
                dp[i][target]=take || ntake;
            }
        }
        return dp[n-1][sum];
    }
};