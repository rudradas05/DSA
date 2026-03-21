class Solution {
public:
    // static bool comp ( pair<int, int> & a, pair<int, int> & b){
    //     rerurn a.second< b.second;
    // }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int count =1;
        int last = points[0][1];
        for(int i =1; i< points.size(); i++){
            if(points[i][0]> last){
                count++;
                last = points[i][1];
            }
        }
        return count;
    }
};