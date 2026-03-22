class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int i =0;
        for(i =0; i< nums1.size() ; i++){
            if(nums1[i]%2==1)break;
        }
        if(i == nums1.size())return true;

        // try to get all odds
        int minele = INT_MAX;
        for(int i =0; i< nums1.size(); i++){
            if(nums1[i]%2==1)minele = min(minele, nums1[i]);

        }
        for(int i=0; i< nums1.size(); i++){
            if(nums1[i]%2==0 && nums1[i]<minele) return false;
        }
        return true;
    }
};