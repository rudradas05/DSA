class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0;
        int high = s.size();
        vector<int> ans;
        for (auto c : s) {
            if (c == 'I') {
                ans.push_back(low);
                low++;
            } else if (c == 'D') {
                ans.push_back(high);
                high--;
            }
        }
        ans.push_back(low);
        return ans;
    }
};