class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        

        // try to get all odds
        int minele = INT_MAX;
        for(int i =0; i< nums1.size(); i++){
            if(nums1[i]%2==1)minele = min(minele, nums1[i]);

        }
        if(minele== INT_MAX)return true;
        for(int i=0; i< nums1.size(); i++){
            if(nums1[i]%2==0 && nums1[i]<minele) return false;
        }
        return true;
    }
};