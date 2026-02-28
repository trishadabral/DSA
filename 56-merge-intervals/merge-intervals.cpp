class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());
        int r=intervals.size();
        int current_start=intervals[0][0],current_end=intervals[0][1];
        for(int i=1;i<r;i++){
            int next_start=intervals[i][0],next_end=intervals[i][1];
            if(current_end>=next_start){
                current_end=max( current_end,next_end);
            }
            else {
                res.push_back({current_start,current_end});
                current_start = next_start;
                current_end = next_end;
            }
        }
        res.push_back({current_start,current_end});
        return res;
    }
};