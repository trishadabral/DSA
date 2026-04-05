class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0,l=0,u=0,d=0,i=0;
        int n=moves.size();
        while(i<n){
            if(moves[i]=='U')u++;
            else if(moves[i]=='D')d++;
            else if(moves[i]=='R')r++;
            else if(moves[i]=='L')l++;
            i++;
        }
        if(u==d && r==l)return true;
        return false;
    }
};