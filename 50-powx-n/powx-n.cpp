class Solution {
public:
    double calcPow(double x, long long n){
        if(n==0)return 1;
        if(n==1)return x;
        double h=calcPow(x,n/2);
        if(n%2==0)return h*h;
        return h*h*x;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(n<0)x=1/x;
        return calcPow(x,abs(N));
    }
};