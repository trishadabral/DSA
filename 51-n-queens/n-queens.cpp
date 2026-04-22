class Solution {
public:
    void solve(int col,int n,vector<string>&ds,vector<int>&leftrow,vector<int>&upperd,vector<int>&lowerd,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(ds);
            return;
        }
        for(int r=0;r<n;r++){
            if(leftrow[r]==0 && lowerd[col+r]==0 && upperd[n-1 +col-r]==0){
                ds[r][col]='Q';
                leftrow[r]=1;
                lowerd[col+r]=1;
                upperd[n-1+col-r]=1;
                solve(col+1,n,ds,leftrow,upperd,lowerd,ans);
                ds[r][col]='.';
                leftrow[r]=0;
                lowerd[col+r]=0;
                upperd[n-1+col-r]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> ds(n, string(n, '.'));
        vector<int>leftrow(n,0),upperd(2*n -1),lowerd(2*n -1);
        solve(0,n,ds,leftrow,upperd,lowerd,ans);
        return ans;
    }
};