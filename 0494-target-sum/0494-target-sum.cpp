class Solution {
public:

    vector<vector<int>> dp;
    int solve (int ind, int sum , vector<int> & nums, int target){
        if(ind> nums.size())return 0;
        if(ind == nums.size()){
            return (sum == target) ? 1: 0; 
        }
        int add = solve(ind+1, sum+ nums[ind],nums, target );
        int subs = solve(ind +1, sum-nums[ind], nums, target);
        return add + subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, vector<int> (n+1, -1));
        return solve ( 0, 0 , nums, target);
    }
};