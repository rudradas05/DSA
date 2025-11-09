class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasFilled = 0;
        int gasUsed = 0;
        for (int i = 0; i < gas.size(); i++) {
            gasUsed += cost[i];
            gasFilled += gas[i];
        }
        if (gasUsed > gasFilled)
            return -1;

        int start = 0;
        int tank = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
