class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>pos;
        for (int i =0;i<nums.size();i++) {
            pos[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        //i<j<k
        // (j-i)+(k-j)+(k-i)-> 2(k-i)
        //k->max index
        //i->min index
        for (auto &p:pos) {
            vector<int>& v=p.second;
            if(v.size()>=3) {
                for(int i=0;i+2<v.size();i++) {
                    ans=min(ans, 2*(v[i+2]-v[i]));//min for every triplet pair that exist
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};