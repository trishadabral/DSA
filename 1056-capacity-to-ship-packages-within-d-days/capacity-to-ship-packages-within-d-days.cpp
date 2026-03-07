class Solution {
public:
    bool possible(vector<int>& weights, int days,int m){
        int sum=0,t=1;
        for(int w:weights){
            if(sum+w>m){
                t++;
                sum=w;
            }
            else{
                sum+=w;
            }
        }
        return t<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*(max_element(weights.begin(),weights.end())),h=0,m;
        for(int x:weights)h+=x;
        while(l<=h){
            m=l+(h-l)/2;
            if(possible(weights,days,m)){
                h=m-1;
            }
            else l=m+1;
        }
        return l;
    }
};