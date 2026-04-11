class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c); 
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
        int maxi=0;
        int count =0;
        for(int i =0; i< k ; i++){
            if(isVowel(s[i]))count++;
            maxi = count;
        }
        for(int i=k ; i< s.size(); i++){
            if(isVowel(s[i]))count++;
            if(isVowel(s[i-k]))count--;
            maxi = max(maxi, count);

        }
        return maxi;
    }
};