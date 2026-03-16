class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int r=q.front().first;
            int s=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=s+dir[i][1];
                if(nr>=0 && nr<n && nc<m && nc>=0 && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)c++;
            }
        }
        return c;
    }
};