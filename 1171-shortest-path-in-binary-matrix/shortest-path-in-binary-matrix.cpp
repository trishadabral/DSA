class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        queue<vector<int>>q;
        vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0},{-1,1},{1,-1},{-1,-1},{1,1}};
        q.push({0,0,1});
        grid[0][0]=1;
        int x,y,d;
        while(!q.empty()){
            auto it=q.front();
            x=it[0];y=it[1];d=it[2];
            q.pop();
            if(x==n-1 && y==n-1)return d;
            for(const auto& p:dir){
                int nx=x+p[0];
                int ny =y+p[1];
                if((nx>=0 && nx<n)&&(ny>=0 && ny<n)&&(grid[nx][ny]==0)){
                    grid[nx][ny]=1;
                    q.push({nx,ny,d+1});
                }
            }
        }
        return -1;
    }
};