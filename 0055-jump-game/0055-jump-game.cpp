class Solution {
public:
    bool f(int ind, vector<int> & nums, vector<int> &dp){
        if(ind==0)return true;
        if(dp[ind]!=-1)return dp[ind];
        for(int k = 0; k<ind; k++){
            if(k+nums[k]>=ind){
                if(f(k,nums,dp))return true;
            }
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1, nums, dp);
    }
};