class Solution{
public:
    vector<int> nextGreaterElement(vector<int>& nums1,vector<int>& nums2){
        unordered_map<int,int>m;
        stack<int>s;
        for(int x:nums2){
            while(!s.empty()&&x>s.top()){
                m[s.top()]=x;
                s.pop();
            }
            s.push(x);
        }
        while(!s.empty()){
            m[s.top()]=-1;
            s.pop();
        }
        vector<int>ans;
        for(int x:nums1)ans.push_back(m[x]);
        return ans;
    }
};