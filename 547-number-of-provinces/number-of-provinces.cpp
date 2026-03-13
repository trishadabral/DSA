class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int node,vector<bool>& vis){
        vis[node]=true;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[node][j]==1 && vis[j]!=true ){
                vis[j]=true;
                dfs(isConnected,j,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(isConnected,i,vis);
            }
        }
        return c;
    }
};