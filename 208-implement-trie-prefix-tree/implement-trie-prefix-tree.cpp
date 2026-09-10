struct node{
    node* child[26]={nullptr};
    bool flg=false;
    bool containkey(char ch){
        return child[ch-'a']!=nullptr;
    }
    void put(char ch,node* n){
        child[ch-'a']=n;
    }
    node* next(char ch){
        return child[ch-'a'];
    }
    void setflag(){
        flg=true;
    }
    bool isend(){
        return flg==true;
    }
};
class Trie {
    private:
    node* root;
    public:
    Trie() {
        root=new node();
    }
    void insert(string word) {
        node* curr=root;
        for(char ch:word){
            if(!(curr->containkey(ch))){
                curr->put(ch,new node());
            }
            curr=curr->next(ch);
        }
        curr->setflag();
    }
    
    bool search(string word) {
        node* curr=root;
        for(char ch:word){
            if(!(curr->containkey(ch))){
                return false;
            }
            curr=curr->next(ch);
        }
        return curr->isend();
    }
    
    bool startsWith(string prefix) {
        node* curr=root;
        for(char ch:prefix){
            if(!(curr->containkey(ch))){
                return false;
            }
            curr=curr->next(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */