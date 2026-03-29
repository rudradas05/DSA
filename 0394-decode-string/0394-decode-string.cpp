class Solution {
public:
    string solve(string& s, int &i) {
        string result = "";
        int num = 0;
        while (i < s.size()) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
            } else if (c == '[') {
                i++;
                string temp = solve(s, i);
                while (num--) {
                    result += temp;
                }
                num = 0;
            } else if (c == ']') {
                i++;
                return result;
            } else {
                result += c;
                i++;
            }
        }
        return result;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};