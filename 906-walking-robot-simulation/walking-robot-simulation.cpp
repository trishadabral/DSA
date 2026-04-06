class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (auto &obs : obstacles) {
            st.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        int x = 0, y = 0;
        int dir = 0; // 0=N, 1=E, 2=S, 3=W
        int ans = 0;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4; // turn right
            } 
            else if (cmd == -2) {
                dir = (dir + 3) % 4; // turn left
            } 
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    string pos = to_string(nx) + "," + to_string(ny);
                    if (st.count(pos)) break;
                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};