class Solution {
public:
    vector<int>parent;
    vector<vector<int>>ans;
    int findparent(int u){
        while(parent[u]>=0){
            u=parent[u];
        }
        return u;
    }
    void dsunion(int u,int v){
        int p1=findparent(u);
        int p2=findparent(v);
        if(p1==p2){
            ans.push_back({u,v});
        }
        else{
            if(abs(parent[p1])>abs(parent[p2])){
                parent[p1]+=parent[p2];
                parent[p2]=p1;
            }
            else{
                parent[p2]+=parent[p1];
                parent[p1]=p2;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=0;i<n;i++)parent[i]=-1;
        for(auto e:edges){
            dsunion(e[0],e[1]);
        }
        return ans.back();
    }
};