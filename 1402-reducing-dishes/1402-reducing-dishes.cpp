class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int total = 0, sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += satisfaction[i];
            total = max(total, total + sum);
        }
        return total;
    }
};