class Solution {
public:
    string toBinary(int x) {
        if (x == 0)
            return "0";
        string res = "";
        while (x > 0) {
            if (x % 2 == 0)
                res.push_back('0');
            else {
                res.push_back('1');
            };
            x = x / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};