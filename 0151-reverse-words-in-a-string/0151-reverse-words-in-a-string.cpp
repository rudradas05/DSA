class Solution {
public:
    string reverseWords(string s) {
        string str ="";
        stack<string> st;
        for(int i = 0 ; i< s.size(); i++){
            if(s[i]==' '){
                if(str!=""){
                    st.push(str);
                    str ="";
                }
                
            }else{
                str+=s[i];
            }
        }
        if(!str.empty())st.push(str);
        string res;
        while(!st.empty()){
            if(res.empty()){
               res+= st.top();
                st.pop();
            }else{
                res+=' ';
                res+= st.top();
                st.pop();
            }
        }
        return res;
    }
};