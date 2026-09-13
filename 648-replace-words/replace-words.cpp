class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>s(dictionary.begin(),dictionary.end());
        stringstream ss(sentence);
        string word,ans="";
        while(ss>>word){
            string root="";
            for(char c:word){
                root+=c;
                if(s.count(root))break;
            }
            if(!s.count(root))root=word;
            if(ans!="")ans+=" ";
            ans+=root;
        }
        return ans;
    }
};