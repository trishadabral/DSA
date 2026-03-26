class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxp=0;
        for(int i:prices){
            minprice=min(minprice,i);
            int p=i-minprice;
            maxp=max(maxp,p);
        }
        return maxp;
    }
};