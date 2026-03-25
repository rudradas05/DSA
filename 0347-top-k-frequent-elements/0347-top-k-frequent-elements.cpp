class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num : nums){
            freq[num]++;
        }
        vector<pair<int, int>> temp (freq.begin(), freq.end());
        sort(temp.begin(), temp.end(), [](auto & a, auto & b){
            return a.second> b.second;
        });
        vector<int> ans;
        for(int i=0; i< k ; i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};