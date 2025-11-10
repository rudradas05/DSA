class Solution {
public:
    int mod = 1e9 + 7;
    long long modPower(long long base, long long exp) {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base;
        long long res = 1;
        long long half = modPower(base, exp / 2);
        res = (half * half) % mod;
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenCnt = (n + 1) / 2;
        long long oddCnt = n / 2;
        long long ans = (modPower(5, evenCnt) * modPower(4, oddCnt)) % mod;
        return int(ans);
    }
};