class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp =0;
        for(int i =0; i< nums.size(); i++){
            temp = temp^ i^ nums[i];
        }
        return temp^ nums.size();
    }
};