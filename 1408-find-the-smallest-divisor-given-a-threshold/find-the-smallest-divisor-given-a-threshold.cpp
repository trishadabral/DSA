class Solution {
public:
    bool check(vector<int>& nums, int threshold,int m){
        int sum=0;
        for(int x:nums){
            sum+=(x+m-1)/m;
        }
        if(sum<=threshold)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,m,ans=INT_MAX;
        int h=*(max_element(nums.begin(),nums.end()));
        while(l<=h){
            m=l+(h-l)/2;
            if(check(nums,threshold,m)){
                ans=min(ans,m);
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};