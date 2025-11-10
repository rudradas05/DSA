class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int fRow = 0;
        int lRow = m-1;
        int fCol = 0;
        int lCol = n-1;
        int rowTarget = -1;
        while(fRow<=lRow && lRow >=0 && fRow<m){
            int curRow = fRow+(lRow-fRow)/2;
            if(matrix[curRow][0]<=target && matrix[curRow][n-1]>=target){
                rowTarget = curRow;
                break;
            }else if(target<matrix[curRow][0]){
                lRow = curRow-1;
            }else{
                fRow = fRow+1;
            }
        }
        if(rowTarget==-1)return false;
        while(fCol<=lCol && fCol<n && lCol>=0){
            int curCol = fCol+(lCol-fCol)/2;
            if(matrix[rowTarget][curCol]==target)return true;
            else if(matrix[rowTarget][curCol]>target)lCol= curCol-1;
            else fCol = fCol+1;
        }
        return false;
    }
};