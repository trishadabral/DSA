class Solution {
public:
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j){
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;
        
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int d=0; d<4; d++){
                int nr = x + dir[d][0];
                int nc = y + dir[d][1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                   !vis[nr][nc] && grid[nr][nc]=='1'){
                    
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        
        return count;
    }
};