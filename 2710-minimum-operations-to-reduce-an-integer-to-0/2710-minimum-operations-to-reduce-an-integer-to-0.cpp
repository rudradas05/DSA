class Solution {
public:
    int minOperations(int n) {
        int ops = 0;
        while (n > 0) {
            int low = 1 << (int)log2(n);
            int high = low << 1;
            if (n - low <= high - n) {
                n -= low;
            } else {
                n = high-n;
            }
            ops++;
        }
        return ops;
    }
};