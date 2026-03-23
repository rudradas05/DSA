class Solution {
public:
    int totalSum;
    vector<vector<int>> dp;
    int solve(int ind, int sum, vector<int>& nums, int target) {
        if (ind == nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        if (dp[ind][sum + totalSum] != -1)
            return dp[ind][sum + totalSum];
        int add = solve(ind + 1, sum + nums[ind], nums, target);
        int subs = solve(ind + 1, sum - nums[ind], nums, target);
        return dp[ind][sum+totalSum] = add + subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        dp.resize(n, vector<int>(2*totalSum+1, -1));
        return solve(0, 0, nums, target);
    }
};