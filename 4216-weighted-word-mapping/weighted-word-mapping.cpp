class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string s;
        for(int i=0;i<n;i++){
            int sum=0;
            for(char x:words[i]){
               sum+= weights[x-'a'];
            }
            sum=sum%26;
            char r='z'-sum;
            s+=r;
        }
        return s;
    }
};