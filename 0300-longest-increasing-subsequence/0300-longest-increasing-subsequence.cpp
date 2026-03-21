class Solution {
public:
    vector<vector<int>> dp;
    int f(int ind, int prev, vector<int>& nums) {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev+1];

        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + f(ind + 1, ind, nums);
        }
        int skip = f(ind + 1, prev, nums);

        return dp[ind][prev + 1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n+1, -1));

        return f(0, -1, nums);
    }
};