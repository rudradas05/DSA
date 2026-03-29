class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool isVowelString(string s) {
        if (isVowel(s[0]) && isVowel(s[s.size() - 1])) {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> res;
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (isVowelString(words[i - 1])) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int count = prefix[r+1] - prefix[l];
            res.push_back(count);
        }
        return res;
    }
};