class Solution {
public:

    vector<vector<int>> dp;

    bool isPal(int l, int r, string &s){

        if(l>=r)return true;
        if(dp[l][r]!=-1)return dp[l][r];
        if(s[l]==s[r] and isPal(l+1, r-1, s)){
            return dp[l][r]=1;
        }
        return dp[l][r]=0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        dp.assign(n, vector<int> (n, -1));

  

        int start = 0;
        int maxLen = 0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                if(isPal(i,j,s) && j-i+1 > maxLen){
                    start = i;
                    maxLen = j-i+1;
                }

            }
        }

        return s.substr(start,maxLen);
    }
};