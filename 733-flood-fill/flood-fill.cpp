class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int n=grid.size();
        int m=grid[0].size();
        int org=grid[sr][sc];
        if(org == color) return grid;
        grid[sr][sc] = color;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
                auto item=q.front();
                q.pop();
                int x=item.first;
                int y=item.second;
                for(int l=0;l<4;l++){
                    int d1=x+dir[l][0];
                    int d2=y+dir[l][1];
                    if(d1>=0 && d1<n && d2>=0 && d2<m && grid[d1][d2]==org){
                        grid[d1][d2]=color;
                        q.push({d1,d2});
                    }
                }
        }

        return grid;
    }
};