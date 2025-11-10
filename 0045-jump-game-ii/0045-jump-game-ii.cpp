class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < n-1; i++) {
            start = max(start, i + nums[i]);
            if (i == end) {
                res++;
                end = start;
            }
        }
        return res;
    }
};