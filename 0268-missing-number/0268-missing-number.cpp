class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp =nums.size();
        for(int i =0; i< nums.size(); i++){
            temp = temp^ i^ nums[i];
        }
        return temp;
    }
};