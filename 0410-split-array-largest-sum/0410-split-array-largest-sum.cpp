class Solution {
public:

    bool isPossible(vector<int> & nums, long long maxSum, int k){
        int parts =1;
        long long sum =0;
        for(int i =0; i< nums.size(); i++){
            if(sum+nums[i]<=maxSum){
                sum+=nums[i];
            }else{
                sum=nums[i];
                parts++;
            }
        }
        return parts<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin(),nums.end());
        long long r = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans =r;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(isPossible(nums, mid, k)){
                ans = mid;
                r=mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};