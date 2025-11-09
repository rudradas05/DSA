class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int workerId = logs[0][0], maxTime = logs[0][1], prevTime = logs[0][1];
        
        for (int i = 1; i < logs.size(); i++) {
            int curTime = logs[i][1] - prevTime;
            if (curTime > maxTime || (curTime == maxTime && logs[i][0] < workerId)) {
                maxTime = curTime;
                workerId = logs[i][0];
            }
            prevTime = logs[i][1];
        }
        return workerId;
    }
};
