class Solution {
public:
    
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum =0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i = 0 ; i<k; i++){
            int val = happiness[i]-i;
            if(val>0) sum+=val;
        }
        return sum;
    }
};