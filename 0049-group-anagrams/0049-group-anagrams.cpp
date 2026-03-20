class Solution {
public:
    bool isAnagrams(string& s, string& t) {
        if (s.size() != t.size())
            return false;
        vector<char> v(30, 0);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            v[t[i] - 'a']--;
        }
        for (auto ele : v) {
            if (ele != 0)
                return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<bool> isUsed(strs.size(), 0);

        for (int i = 0; i < strs.size(); i++) {
            if (isUsed[i])
                continue;
            vector<string> groups;

            groups.push_back(strs[i]);

            isUsed[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (!isUsed[j] && isAnagrams(strs[i], strs[j])) {
                    groups.push_back(strs[j]);
                    isUsed[j] = true;
                }
            }
            res.push_back(groups);
        }
        return res;
    }
};