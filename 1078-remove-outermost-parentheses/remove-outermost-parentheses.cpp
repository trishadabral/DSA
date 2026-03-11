class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string st="";
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='(' ){
                if(c>0)st+=s[i];
                c++;
            }    
            else {
                c--;
                if(c> 0)st+= s[i];}
        }
        return st;
    }
};