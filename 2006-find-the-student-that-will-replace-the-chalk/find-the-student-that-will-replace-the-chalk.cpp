class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long c=0;
        for(int x:chalk)c+=x;
        int rem=k%c;
        for(int i=0;i<chalk.size();i++){
            if(rem<chalk[i])return i;
            rem-=chalk[i];
        }
        return -1;
    }
};