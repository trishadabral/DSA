class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>m;
        for(int x:nums)m[x]++;
        int ans=0;
        for(auto x:m){
            if(m.count(x.first+1)){
                ans=max(ans,x.second+m[x.first+1]);
            }
        }
        return ans;
    }
};