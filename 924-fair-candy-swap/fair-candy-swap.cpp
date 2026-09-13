class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int a=0,b=0;
        for(int x:aliceSizes)a+=x;
        for(int x:bobSizes)b+=x;
        int diff=(a-b)/2;
        set<int>s(bobSizes.begin(),bobSizes.end());
        for(int x:aliceSizes){
            if(s.count(x-diff)){
                return {x,x-diff};
            }
        }
        return {};
    }
};