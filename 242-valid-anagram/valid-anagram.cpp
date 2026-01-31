class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int>f1(26,0);
        for(char x:s)f1[x-'a']++;
        for(char x:t)f1[x-'a']--;
        for(int x:f1){
            if(x!=0)return false;
        }
        return true;
    }    
};