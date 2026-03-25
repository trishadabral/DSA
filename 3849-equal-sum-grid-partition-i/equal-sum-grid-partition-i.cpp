class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long halfsum=0,totalsum=0,rsum=0,csum=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                totalsum+=grid[i][j];
            }
        }
        if(totalsum%2!=0)return false;
        halfsum=totalsum/2;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                rsum+=grid[i][j];
            }
            if(rsum==halfsum)return true;
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                csum+=grid[i][j];
            }
            if(csum==halfsum)return true;
        }
        return false;
    }
};