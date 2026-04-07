class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setA;
        for (int i = 0; i < nums1.size(); i++) {
            
            setA.insert(nums1[i]);
        }
        unordered_set<int> intersection;
        for (int i = 0; i < nums2.size(); i++) {
            int x = nums2[i];
            
            if (setA.count(x)) {
                intersection.insert(x);
            }
        }

        vector<int> result(intersection.begin(), intersection.end());
        sort(result.begin(), result.end());
        return result;
        
    }
};