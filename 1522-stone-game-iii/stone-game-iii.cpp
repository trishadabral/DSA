class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& stoneValue,int i){
        if(i>=n)return 0;
        if(dp[i]!=INT_MIN)return dp[i];
        int res=INT_MIN;
        res=max(res,stoneValue[i]-solve(stoneValue,i+1));
        if(i+1<n){
            res=max(res,stoneValue[i]+stoneValue[i+1]-solve(stoneValue,i+2));
        }
        if(i+2<n){
            res=max(res,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(stoneValue,i+3));
        }
        return dp[i]=res;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.resize(n+1,INT_MIN);
        int k=solve(stoneValue,0);
        if(k>0)return "Alice";
        else if(k<0)return "Bob";
        else return "Tie";
    }
};