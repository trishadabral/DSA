class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
       if (j==0 && i==0 ) return grid[0][0];
       if (i < 0 || j < 0) return INT_MAX;
       if (dp[i][j]!=-1)return dp[i][j];
       int l=f(i-1,j,dp,grid);
       int r=f(i,j-1,dp,grid);
       return dp[i][j]=grid[i][j]+min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size(),n = grid[0].size();
       vector<vector<int>>dp(m,vector<int>(n,-1));
       return f(m-1,n-1,dp,grid);
    }
};