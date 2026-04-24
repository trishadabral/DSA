class Solution {
public:
    int encrypt(int x){
        int res=INT_MIN,c=0;
        while(x>0){
            int rem=x%10;
            if(rem>res)res=rem;
            x/=10;
            c++;
        }
        int d=0;
        while(c>0){
            d=d*10+res;
            c--;
        }
        return d;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=encrypt(x);
        }
        return sum;
    }
};