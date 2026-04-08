class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;

        int x = 0;
        int y = 0;
        int maxDist = 0;

        set<pair<int, int>> st;
        for (auto& o : obstacles) {
            st.insert({o[0], o[1]});
        }

        for (int cmd : commands) {
            if (cmd == -1) {
                d = (d + 1) % 4;

            } else if (cmd == -2) {
                d = (d + 3) % 4;
            } else {
                for (int s = 0; s < cmd; s++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    if (st.contains({nx, ny}))
                        break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
        return maxDist;
    }
};