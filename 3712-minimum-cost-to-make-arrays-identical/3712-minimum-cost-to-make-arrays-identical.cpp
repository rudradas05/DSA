class Solution {
public:
     
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long cost1=0;
        long long cost2 = k;
        for(int i = 0; i<n ; i++){
            cost1+=abs(arr[i]-brr[i]);
        }

        vector<int> a = arr;
        vector<int> b = brr;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i< n ; i++){
            cost2+= abs(a[i]-b[i]);
        }
        return min(cost1, cost2);
    }
};