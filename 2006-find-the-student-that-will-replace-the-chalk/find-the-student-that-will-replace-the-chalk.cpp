#define ll long long
class Solution {
public:
    ll chalkReplacer(vector<int>& chalk, int k) {
        ll sum = 0, n = chalk.size();
        for (int i = 0; i < n; i++) {
             sum +=   chalk[i];
        }
        k %= sum;

        for (ll i = 0; i < n; i++) {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};