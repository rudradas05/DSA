class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome (int l , int r, string & s){
        if(l>=r)return true;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r] && isPalindrome(l+1, r-1, s)){
            return dp[l][r]=1;
        }
        return dp[l][r]=0;
    }
    int countSubstrings(string s) {
        int n = s.size();
        dp.resize(n , vector<int> (n, -1));
        int count =0;
        for(int i =0; i< n ;i++){
            for(int j =i ; j< n ; j++){
                if(isPalindrome(i, j , s)){
                    count++;
                }
            }
        }
        return count;
    }
};