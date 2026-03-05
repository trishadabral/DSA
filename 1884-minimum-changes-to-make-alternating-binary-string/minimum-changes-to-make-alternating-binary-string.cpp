class Solution {
public:
    int minOperations(string s) {
        int n=s.length(),c=0,f=0;
        for(int i=0;i<n;i++){
           if(i%2==0){
               if(s[i]=='0')c++;
               else f++;
           }
           else{
             if(s[i]=='1')c++;
               else f++;
           }
        }
        return min(c,f);
    }
};