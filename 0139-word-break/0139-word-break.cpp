class Solution {
public:
    unordered_set<string> dict;
    vector<int> dp;

    bool solve (int i , string & s){
        if(i == s.size())return true;
        if(dp[i]!=-1)return dp[i];

        for(int j = i ; j< s.size(); j++){
            string word = s.substr(i, j-i+1);
            if (dict.count(word) && solve(j + 1, s)) {
                return dp[i] = 1;
            }
        }return dp[i]=0;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp.resize(s.size(), -1);

        return solve(0, s);

    }
};