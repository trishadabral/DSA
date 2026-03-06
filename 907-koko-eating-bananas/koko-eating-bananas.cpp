class Solution {
public:
    long long checkvalid(vector<int>& piles,int k){
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i] + k - 1) / k;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi=*(max_element(piles.begin(),piles.end()));
        int l=1,m,k=INT_MAX;
        while(l<=hi){
            m=l+(hi-l)/2;
            long long sum=checkvalid(piles,m);
            if(sum<=h){
                k=min(k,m);
                hi=m-1;
            }
            else l=m+1;
        }
        return k;
    }
};