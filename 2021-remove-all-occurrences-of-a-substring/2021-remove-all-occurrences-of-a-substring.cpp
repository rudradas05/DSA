class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st1;
        vector<char> v;
        for(int i = 0; i<s.size(); i++){
            st1.push(s[i]);
              int j=part.size()-1;
               while(!st1.empty() and j>=0){
                if(st1.top()!=part[j]) break;
                v.push_back(st1.top());
                st1.pop();
                j-=1;
               }
               if(v.size()!=part.size()){
                reverse(v.begin(),v.end());
                for(auto ele:v) st1.push(ele);
               }
            v.clear();
        }
        string ans="";
        while(!st1.empty()){
            ans+=st1.top();
            st1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};