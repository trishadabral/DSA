class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h,n=citations.size();
        sort(citations.begin(),citations.end());
        for(int i=0;i<n;i++){
            h=n-i;
            if(citations[i]>=h)return h;
        }
        return 0;
    }
};