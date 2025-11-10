class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustPerson(n+1, 0);
        vector<int> trustedPerson(n+1,0);
        for(auto t : trust){
            int a = t[0];
            int b = t[1];
            trustPerson[a]++;
            trustedPerson[b]++;
        }
        for(int i = 1 ; i<=n; i++){
            if(trustPerson[i]==0 && trustedPerson[i] ==n-1){
                return i;
            }
        }
        return -1;
    }
};