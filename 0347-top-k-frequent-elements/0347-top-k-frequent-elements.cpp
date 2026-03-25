class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;

        for (auto& p : freq) {
            maxHeap.push({p.second, p.first});
        }
        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};