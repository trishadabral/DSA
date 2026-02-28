class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){ return a[0]<b[0];});
        vector<vector<int>>res;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(res.empty())res.push_back({start,end});
            else{
                vector<int>&last=res.back();
                if(last[1]<start)res.push_back({start,end});
                else{
                    last[1]=max(last[1],end);
                }
            }
        }
        return res;
    }
};