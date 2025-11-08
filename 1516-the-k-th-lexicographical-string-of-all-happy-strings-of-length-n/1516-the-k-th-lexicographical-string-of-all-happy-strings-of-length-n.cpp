class Solution {
public:
    int count = 0;
    string answer = "";
    
    void dfs(string curr, int n, int k) {
        if (answer != "") return;  
        if (curr.size() == n) {
            count++;
            if (count == k) answer = curr;
            return;
        }
        for (char c : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != c)
                dfs(curr + c, n, k);
        }
    }

    string getHappyString(int n, int k) {
        dfs("", n, k);
        return answer;
    }
};
