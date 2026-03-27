class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        for (int i=0;i<n;i++) {
            for (int j=0; j < m; j++) {
                // for each element checking for position after kth shift
                if (i%2==0) {
                    if (mat[i][j]!=mat[i][(j+k)%m]) return false;
                } else {
                    if (mat[i][j] != mat[i][(j-k+m)%m]) return false;
                }
            }
        }
        return true;
    }
};