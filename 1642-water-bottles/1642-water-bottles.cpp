class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        if (numExchange <= 1) return INT_MAX;
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};
