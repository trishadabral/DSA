class Solution {
public:
int dfs(vector<vector<int>>& grid ,int i,int j){
    int nr=grid.size();
    int nc=grid[0].size();
    if(i<0 || j<0|| i>=nr||j>=nc||grid[i][j]==0)return 0;
    grid[i][j]=0;
    return 1+(dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1));
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();
        int min_area=0;
        for(int i=0;i<nr;i++){
            for(int j=0;j<nc;j++){
                if(grid[i][j]==1){
                    min_area=max(min_area,dfs(grid,i,j));
                }
            }
        }
        return min_area;
    }
};