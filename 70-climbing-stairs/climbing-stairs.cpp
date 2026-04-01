class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        int curr=0;
        int prev=1,prev1=2;
        for(int i=3;i<=n;i++){
            curr=prev+prev1;
            prev=prev1;
            prev1=curr;
        }
        return curr;
    }
};