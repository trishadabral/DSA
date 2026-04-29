class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
       if (i < 0 || j < 0) return 0;
       if (grid[i][j] == 1) return 0;
       if (i == 0 && j == 0) return 1;
       if (dp[i][j]!=-1)return dp[i][j];
       int l=f(i-1,j,dp,grid);
       int r=f(i,j-1,dp,grid);
       return dp[i][j]=l+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m=obstacleGrid.size(),n = obstacleGrid[0].size();
       vector<vector<int>>dp(m,vector<int>(n,-1));
       return f(m-1,n-1,dp,obstacleGrid);
    }
};