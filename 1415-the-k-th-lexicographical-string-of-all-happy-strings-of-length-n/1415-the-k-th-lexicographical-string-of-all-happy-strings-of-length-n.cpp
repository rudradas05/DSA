class Solution {
public:
    int count =0;
    string ans ="";
    void dfs(string curr, int n , int k){
        if(ans!="") return ;
        if(curr.size()==n){
            count++;
            if(count==k){
                ans = curr;
            }
            return;
        }
        for(auto c : {'a', 'b', 'c'}){
            if(curr.empty() || curr.back()!=c){
                dfs(curr+c, n, k);
            }
        }

    }
    string getHappyString(int n, int k) {
        dfs("",n, k);
        return ans;
    }
};