class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        int ans = 0;

        while (l <= h) {
            int m = l + (h - l) / 2;
            long long sq = 1LL * m * m;

            if (sq == x) return m;
            else if (sq < x) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }
};