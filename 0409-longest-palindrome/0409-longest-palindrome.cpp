class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>freq;
        for(auto c: s){
            freq[c]++;
        }
        int length = 0;
        bool hashOdd = false;
        for(auto & p : freq){
            int count = p.second;
            length+=(count/2)*2;
            if(count%2==1)hashOdd= true;
        }
        if(hashOdd)length+=1;
        return length;
    }
};