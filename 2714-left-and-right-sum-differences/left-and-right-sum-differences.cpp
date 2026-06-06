class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int i,n=nums.size();
        vector<int>leftsum(n,0);
        vector<int>answer(n,0);
        vector<int>rightsum(n,0);
        for(i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i+1];
        }
        for(i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }
        for(i=0;i<n;i++){
            answer[i]=abs(leftsum[i]-rightsum[i]);
        }
        return answer;
    }
};