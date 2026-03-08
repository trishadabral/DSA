class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),c=0;
        vector<int>res(n,1);
        vector<int>right(n,1);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])res[i]=res[i+1]+1;
        }
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                right[i]=right[i-1]+1;
                res[i]=max(res[i],right[i]);
            }
        }
        for(int x:res)c+=x;
        return c;
    }
};