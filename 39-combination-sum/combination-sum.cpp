class Solution {
public:
    void combination(int idx, vector<int>& candidates,vector<vector<int>>& ans,vector<int>& ds,int target){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            combination(idx,candidates,ans,ds,target-candidates[idx]);
            ds.pop_back();
        }
        combination(idx+1,candidates,ans,ds,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combination(0,candidates,ans,ds,target);
        return ans;
    }
};