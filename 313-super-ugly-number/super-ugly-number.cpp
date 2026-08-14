class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        vector<long long>dp(n);
        int k=primes.size();
        vector<long long>idx(k,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            long long  next=LLONG_MAX;
            for(int j=0;j<k;j++){
                next=min(next,dp[idx[j]]*primes[j]);
            }
            dp[i]=next;
            for(int j=0;j<k;j++){
                if(dp[idx[j]]*primes[j]==next)idx[j]++;
            }
        }
        return (int)dp[n-1];
    }
};