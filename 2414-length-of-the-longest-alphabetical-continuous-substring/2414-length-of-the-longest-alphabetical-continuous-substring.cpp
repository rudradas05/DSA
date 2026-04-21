class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxLen = 1;
        int len = 1;
        for (int i = 1; i < s.size(); i++) {

            if (s[i] == s[i - 1] + 1) {
                len++;
            } else {
                len = 1;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};