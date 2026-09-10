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
    int findMaximumXOR(vector<int>& nums) {
        Trie* root=new Trie();
        for(int x:nums)root->insert(x);
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int cur=root->getmax(nums[i]);
            maxi=max(maxi,cur);
        }
        return maxi;
    }
};