class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int d = -(n - 1); d <= (n - 1); d++) {
            vector<int> dia;
            for (int i = 0; i < n; i++) {
                int j = i - d;
                if (j >= 0 && j < n) {
                    dia.push_back(grid[i][j]);
                }
            }
            if (d >= 0) {
                sort(dia.begin(), dia.end(), greater<int>());
            } else {
                sort(dia.begin(), dia.end());
            }
            int idx =0;
            for(int  i =0; i< n ; i++){
                int j =i-d; 
                if(j>=0 && j< n){
                    grid[i][j]= dia[idx];
                    idx++;
                }
            }
        }
        return grid;
    }
};