class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        int n = tiles.size();
        long long cover = 0;
        int ans = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            int start = tiles[i][0];
            int end = start + carpetLen - 1;

            // ✅ FIXED CONDITION
            while (j < n && tiles[j][1] <= end) {
                cover += (tiles[j][1] - tiles[j][0] + 1);
                j++;
            }

            int partial = 0;

            // Partial coverage
            if (j < n && tiles[j][0] <= end) {
                partial = end - tiles[j][0] + 1;
            }

            ans = max(ans, (int)(cover + partial));

            // Remove tile i before moving forward
            cover -= (tiles[i][1] - tiles[i][0] + 1);
        }

        return ans;
    }
};