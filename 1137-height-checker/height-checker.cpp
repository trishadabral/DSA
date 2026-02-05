class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=*max_element(heights.begin(),heights.end());
        int c=0;
        vector<int>cf(n+1);
        vector<int>sorted(heights.size());
        for(int x:heights)cf[x]++;
        for(int i=1;i<n+1;i++)cf[i]+=cf[i-1];
        for(int i=heights.size()-1;i>=0;i--){
            if(cf[heights[i]]!=0){
                cf[heights[i]]--;
                sorted[cf[heights[i]]]=heights[i];
            }
        }
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=sorted[i])c++;
        }
        return c;
    }
};