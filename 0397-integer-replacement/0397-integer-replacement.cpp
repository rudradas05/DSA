class Solution {
public:
    int dfs(long long n, vector<int>& dp) {
        if (n == 1) return 0;
        if (n < dp.size() && dp[n] != -1) return dp[n];

        int steps;
        if (n % 2 == 0) {
            steps = 1 + dfs(n / 2, dp);
        } else {
            steps = 1 + min(dfs(n - 1, dp), dfs(n + 1, dp));
        }

        if (n < dp.size()) dp[n] = steps; 
        return steps;
    }

    int integerReplacement(int n) {
        vector<int> dp(min((long long)n + 2, 1000000LL), -1); 
        return dfs((long long)n, dp);
    }
};