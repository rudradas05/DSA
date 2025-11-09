class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int>& nums, int start, vector<int>& path) {
        if (path.size() >= 2) {
            ans.push_back(path);
        }
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back())
                continue;
            if (used.count(nums[i]))
                continue;
            path.push_back(nums[i]);
            used.insert(nums[i]);
            backTrack(nums, i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        backTrack(nums, 0, path);
        return ans;
    }
};