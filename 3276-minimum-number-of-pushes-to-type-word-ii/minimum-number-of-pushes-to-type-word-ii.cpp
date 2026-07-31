class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        sort(freq.begin(),freq.end(),[](int a,int b){return a>b;});
        int min_step=0;
        for(int i=0;i<26 && freq[i]>0;i++){
           min_step+=freq[i]*(i/8 + 1);
        }
        return min_step;
    }
};