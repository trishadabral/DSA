class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
         int c=0,f=0;
          for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=day)c++;
                else{
                    f+=c/k;
                    c=0;
                }
          }
          f+=c/k;
          if(f>=m)return true;
          else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())return -1;
        int h=*(max_element(bloomDay.begin(),bloomDay.end()));
        int l=*(min_element(bloomDay.begin(),bloomDay.end())),mid,ans=INT_MAX;
        while(l<=h){
            mid=l+(h-l)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};