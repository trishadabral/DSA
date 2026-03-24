class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD=12345;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        vector<int>arr;
        for(int i=0;i<n;i++){
            for(auto it:grid[i]){
                arr.push_back(it%MOD);
            }
        }
        int k=arr.size();
        vector<int>prefix(k,1);
        for(int i=1;i<k;i++){
            prefix[i]=(prefix[i-1]*arr[i-1])%MOD;
        }
        vector<int>surfix(k,1);
        for(int i=k-2;i>=0;i--){
            surfix[i]=(surfix[i+1]*arr[i+1])%MOD;
        }
        vector<int>res(k);
        for(int i=0;i<k;i++){
            res[i]=(prefix[i]*surfix[i])%MOD;
        }
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=res[idx++];
            }
        }
        return ans;
    }
};