class MyHashMap{
public:
    vector<pair<int,int>>bucket[1000];

    MyHashMap(){}

    void put(int key,int value){
        int idx=key%1000;
        for(auto &p:bucket[idx]){
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        bucket[idx].push_back({key,value});
    }

    int get(int key){
        int idx=key%1000;
        for(auto p:bucket[idx]){
            if(p.first==key)return p.second;
        }
        return -1;
    }

    void remove(int key){
        int idx=key%1000;
        for(int i=0;i<bucket[idx].size();i++){
            if(bucket[idx][i].first==key){
                bucket[idx].erase(bucket[idx].begin()+i);
                return;
            }
        }
    }
};