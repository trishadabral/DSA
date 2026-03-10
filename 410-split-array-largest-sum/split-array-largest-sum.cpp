class Solution {
public:
    bool possible(vector<int>& nums, int k, int m){
        int sum = 0, parts = 1;
        for(int n : nums){
            if(sum + n > m){
                parts++;
                sum = n;
            } 
            else{
                sum += n;
            }
        }
        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = h;

        while(l <= h){
            int m = l + (h - l) / 2;

            if(possible(nums, k, m)){
                ans = m;
                h = m - 1;
            } 
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};