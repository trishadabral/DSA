class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        
        // Sort robot indices based on positions
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> st; // stores indices of robots moving right
        
        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push(id);
            } else {
                // Current robot moving left
                while (!st.empty() && healths[id] > 0) {
                    int topId = st.top();
                    
                    if (healths[topId] < healths[id]) {
                        // Right robot dies
                        st.pop();
                        healths[id] -= 1;
                        healths[topId] = 0;
                    }
                    else if (healths[topId] > healths[id]) {
                        // Left robot dies
                        healths[topId] -= 1;
                        healths[id] = 0;
                    }
                    else {
                        // Both die
                        st.pop();
                        healths[topId] = 0;
                        healths[id] = 0;
                    }
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) ans.push_back(healths[i]);
        }
        
        return ans;
    }
};