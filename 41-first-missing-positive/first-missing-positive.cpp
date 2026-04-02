class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n) {
                int c = nums[i] - 1;
                if (nums[i] != nums[c]) {
                    swap(nums[i], nums[c]);
                    continue;
                }
            }
            i++;
        }

        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }

        return n + 1;
    }
};