class Solution {
public:
    bool wordPattern(string pattern, string s) {
         stringstream ss(s);
        vector<string>words;
        string word;
        while(ss>>word)words.push_back(word);
        if(pattern.size()!=words.size())return false;
        map<char,string>m1;
        map<string,char>m2;
        for(int i=0;i<pattern.size();i++){
            char c=pattern[i];
            if(m1.count(c)&&m1[c]!=words[i])return false;
            if(m2.count(words[i])&&m2[words[i]]!=c)return false;
            m1[c]=words[i];
            m2[words[i]]=c;
        }
        return true;
    }
};