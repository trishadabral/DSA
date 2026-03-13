class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),fresh=0;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }
        int time = 0;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty() && fresh!=0){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto item=q.front();
                q.pop();
                int x=item.first;
                int y=item.second;
                for(int l=0;l<4;l++){
                    int d1=x+dir[l][0];
                    int d2=y+dir[l][1];
                    if(d1>=0 && d1<n && d2>=0 && d2<m && grid[d1][d2]==1){
                        fresh--;
                        grid[d1][d2]=2;
                        q.push({d1,d2});
                    }
                }
            }
            time++;
        }
        if(fresh==0)return time;
        return -1;
    }
};