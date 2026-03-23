class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto c: s){
            int a = int(c);
            if(a>=97 && a<=122){
                str+=c;
            }else if (a>=65 && a<=90){
                str+=char(c+32);
            }else if(a>=48 && a<=57){
                str+= c;
            }
        }
        //check for palindrome
        int i =0;
        int j = str.size()-1;
        while(i<j){
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
};