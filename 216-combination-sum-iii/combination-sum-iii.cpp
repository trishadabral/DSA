class Solution {
public:
void solve(int idx, int k, int target,vector<int>&ds,vector<vector<int>>&ans){
    if(k==0 && target==0){
        ans.push_back(ds);
        return ;
    }
    if(k==0 || target<0)return;
    for(int i=idx;i<=9;i++){
        ds.push_back(i);
        solve(i+1,k-1,target-i,ds,ans);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};