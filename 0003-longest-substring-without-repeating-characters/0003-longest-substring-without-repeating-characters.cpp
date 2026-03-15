class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; 
        int l = 0; 
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++){
            while(st.find(s[i])!=st.end()){
              
                st.erase(s[l]);
                  l++;
            }
            int len = i-l+1;
            maxLen = max(maxLen, len);
            st.insert(s[i]);
        
        }

        return maxLen;
    }
};