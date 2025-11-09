class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        
        unordered_map<int, int> freq;
       
        for(int i =0; i<bills.size() ; i++){
            if(bills[i]==5){
                freq[5]++;
            };
            if(bills[i]==10){

                if(freq[5]>=1){
                    freq[10]++;
                    freq[5]--;
                }else{
                    return false;
                }
            }
            if(bills[i]==20){
                if(freq[5]>=1 && freq[10]>=1){
                    
                    freq[5]--;
                    freq[10]--;
                }else if(freq[5]>=3){
                    freq[5]-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};