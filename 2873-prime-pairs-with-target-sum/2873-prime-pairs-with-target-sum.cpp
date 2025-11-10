class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
        int res;
        vector<vector<int>> ans;
        for (int i = 2; i <= n/2; i++) {
            int res = n - i;
            if (isPrime(i) && isPrime(res)) {
                ans.push_back({i, res});
            }
        }
        return ans;
    }
};