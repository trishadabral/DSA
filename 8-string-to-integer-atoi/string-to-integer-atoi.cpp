class Solution {
public:
    int solveAtoi(string &s, int i, long long res, int sign) {
        if (i >= s.size() || !isdigit(s[i])) {
            res *= sign;
            if (res > INT_MAX) return INT_MAX;
            if (res < INT_MIN) return INT_MIN;
            return (int)res;
        }
        int digit = s[i] - '0';
        res=res*10+digit;
        if (sign==1 && res>INT_MAX) return INT_MAX;
        if (sign==-1 && -res<INT_MIN) return INT_MIN;

        return solveAtoi(s,i+1,res,sign);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return solveAtoi(s, i, 0, sign);
    }
};