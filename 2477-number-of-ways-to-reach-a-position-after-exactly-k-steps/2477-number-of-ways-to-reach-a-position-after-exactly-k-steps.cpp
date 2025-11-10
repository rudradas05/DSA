class Solution {
public:
    int mod = 1e9 + 7;

    int f(int pos, int tar, int steps, vector<vector<int>>& dp, int offset) {
        if (steps == 0)
            return pos == tar ? 1 : 0;

        if (dp[steps][pos + offset] != -1)
            return dp[steps][pos + offset];

        long long left = f(pos - 1, tar, steps - 1, dp, offset);
        long long right = f(pos + 1, tar, steps - 1, dp, offset);

        return dp[steps][pos + offset] = (left + right) % mod;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int offset = k + 1000; 
        vector<vector<int>> dp(k + 1, vector<int>(2 * k + 2001, -1));
        return f(startPos, endPos, k, dp, offset);
    }
};
