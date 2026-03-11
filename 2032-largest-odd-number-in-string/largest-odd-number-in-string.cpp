class Solution {
public:
    string largestOddNumber(string num) {
        int c=-1;
        string st="";
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]=='3'||num[i]=='5'||num[i]=='7'||num[i]=='9'||num[i]=='1'){c=i;break;}
        }
        if(c==-1)return "";
        for(int i=0;i<=c;i++){
            st+=num[i];
        }
        return st;
    }
};