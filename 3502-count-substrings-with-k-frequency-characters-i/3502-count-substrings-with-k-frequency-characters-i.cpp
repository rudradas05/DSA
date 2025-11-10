class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        long long count = 0;

        vector<int> freq(26, 0);
        int l = 0;
        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;
            while (l <= r && hasFreqAtLeast(freq, k)) {
                count += n - r;
                freq[s[l] - 'a']--;
                l++;
            }
        }
        return count;
    }
    bool hasFreqAtLeast(vector<int>& freq, int k) {
        for (int f : freq) {
            if (f >= k)
                return true;
        }
        return false;
    }
};