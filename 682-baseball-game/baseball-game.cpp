class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>v;
        for(string s:operations){
            if(s=="C"){
                v.pop_back();
            }
            else if(s=="D"){
                v.push_back(2*v.back());
            }
            else if(s=="+"){
                int n=v.size();
                v.push_back(v[n-1]+v[n-2]);
            }
            else{
                v.push_back(stoi(s));
            }
        }
        int sum=0;
        for(int x:v)sum+=x;
        return sum;
    }
};