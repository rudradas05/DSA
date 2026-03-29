class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

  
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int count = 0;

     
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int sum = prefix[j] - prefix[i - 1];
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};