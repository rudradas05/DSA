#include <bits/stdc++.h>
using namespace std;

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

    int distinctPrimeFactors(vector<int>& nums) {
        vector<bool> seen(1001, false);
        for (auto num : nums) {
            for (int i = 2; i <= 1000; i++) {
                if (isPrime(i) && num%i == 0) {
                    seen[i] = true;
                    while (num % i == 0)num  =num/ i;
                        
                }
            }
        }
        int count = 0;
        for (auto primeFactor : seen) {
            if (primeFactor)
                count++;
        }
        return count;
    }
};
