class Solution {
public:
    int totalSum;
    unordered_map<string, int> mp;

    int solve(int ind, int sum, vector<int>& nums, int target) {
        string str ="";
        if(ind> nums.size()) return 0;
        str = to_string(sum)+"_"+to_string(ind);
        if (mp.find(str)!=mp.end())return mp[str];
        if (ind == nums.size()) {
            if (sum == target) {
                return mp[str]=1;
            }else{
                return mp[str]=0;
            }
        }
        
        int add = solve(ind + 1, sum + nums[ind], nums, target);
        int subs = solve(ind + 1, sum - nums[ind], nums, target);
        return mp[str] = add + subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        

        return solve(0, 0, nums, target);
    }
};