class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int xr, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return (xr == target) ? 0 : -1;
        }

        if (dp[i][xr] != -2) return dp[i][xr];

        int pick = solve(i + 1, xr ^ nums[i], nums, target);

        int remove = solve(i + 1, xr, nums, target);
        if (remove != -1) remove += 1;

        if (pick == -1 && remove == -1)
            return dp[i][xr] = -1;
        else if (pick == -1)
            return dp[i][xr] = remove;
        else if (remove == -1)
            return dp[i][xr] = pick;
        else
            return dp[i][xr] = min(pick, remove);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

    
        dp.assign(n, vector<int>(20000, -2));

        return solve(0, 0, nums, target);
    }
};