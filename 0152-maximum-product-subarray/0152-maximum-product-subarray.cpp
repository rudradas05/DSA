class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1;
        int maxi = INT_MIN;
        for(int i =0; i< nums.size(); i++){
            if(nums[i]!=0){
                product*= nums[i];
                maxi = max(product, maxi);
            }else{
                product =1;
                maxi = max(maxi, 0);
            }
        }
        product =1;
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i]!=0){
                product*= nums[i];
                maxi = max(product, maxi);
            }else{
                product =1;
                maxi = max(maxi, 0);
            }
        }
        return maxi;
    }
};