class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s;
        s.reserve(nums.size() * 2);         // avoid rehashing
        s.max_load_factor(0.7f);
        for (int x : nums) s.insert(x);

        int best = 0;
        for (int x : s) {                   // iterate set (no duplicates)
            if (s.find(x - 1) == s.end()) { // start of sequence
                int cur = x;
                int len = 1;
                while (s.find(cur + 1) != s.end()) {
                    ++cur;
                    ++len;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};
