class Solution {

public:
    bool isPossible(vector<int>& position, int gap, int m) {
        int placed =1;
        int prev =position[0];
        for(int i=1; i< position.size(); i++){
            if(position[i]-prev>=gap){
                placed++;
                prev= position[i];
            }
        }
        return placed>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0;
        int r = position[n - 1] - position[0];
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(position, mid, m)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};