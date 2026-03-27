class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;
        
        for(auto w: words1){
            freq1[w]++;
        }
        for(auto w: words2){
            freq2[w]++;

        }
        int count=0;
        for(auto & it : freq1){
            if(it.second==1 && freq2[it.first]==1){
                count++;
            }
        }
        return count;
    }
};