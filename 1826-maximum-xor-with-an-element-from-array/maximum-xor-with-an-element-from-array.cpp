struct node{
    node* child[2]={nullptr};
    bool flg=false;
    bool containkey(int ch){
        return child[ch]!=nullptr;
    }
    void put(int ch,node* n){
        child[ch]=n;
    }
    node* next(int ch){
        return child[ch];
    }
    void setflag(){
        flg=true;
    }
};
class Trie {
    private:
    node* root;
    public:
    Trie() {
        root=new node();
    }
    void insert(int num) {
        node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->child[bit]==nullptr)
                curr->child[bit] = new node();

            curr = curr->child[bit];
        }
    }
    int getmax(int x){
        node * curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            int op=1-bit;
            if(curr->child[op]!=nullptr){
                ans|=(1<<i);
                curr=curr->next(op);
            }
            else{
                curr=curr->next(bit);
            }
        }
        return ans;
    }    
};

class Solution {
public:
    vector<int> validarr(vector<int>&nums,int y){
        vector<int>ans;
        for(int k:nums){
            if(k<=y)ans.push_back(k);
        }
        return ans;
    }
    void maketrie(Trie* root,vector<int>& temp){
        for(int k:temp){
            root->insert(k);
        }
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie root;
        int k=nums.size();
        int n=queries.size();
        vector<int>answer(n);
        sort(nums.begin(),nums.end());
        vector<vector<int>>q;
        for(int i=0;i<n;i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
         int i=0;
        sort(q.begin(),q.end());
        for(auto &it:q){
            int x=it[1];
            int y=it[0];
            int idx=it[2];
           
            while(i<k && nums[i]<=y){
                root.insert(nums[i]);
                i++;
            }
            if(i==0)answer[idx]=-1;
            else{
                answer[idx]=root.getmax(x);
            }
        }
        return answer;
    }
};