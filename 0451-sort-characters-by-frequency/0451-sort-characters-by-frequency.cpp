class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto ch: s){
            freq[ch]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for(auto & p: freq){
            maxHeap.push({p.second, p.first});
        }
        string result;
        while(!maxHeap.empty()){
            auto[count, ch] = maxHeap.top();
            result.append(count, ch);
            maxHeap.pop();
        }
        return result;
    }
};