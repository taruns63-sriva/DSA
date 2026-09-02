class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        string str= "";
        stack<char>st;

        for(char ch : s){
            if(!st.empty() && abs(st.top() - ch) == 32){
                st.pop();
            }
            
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};