class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size(),i;
        if(n==1)return true;
        for(i=1;i<n;i++){
            if(s[i]=='0')break;
        }
        for(i;i<n;i++){
            if(s[i]=='1')return false;
        }
        return true;
    }
};