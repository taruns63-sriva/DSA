class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st,st1;
        int n = s.size();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c=='(') st.push(i);
            else if (c=='*') st1.push(i);
            else {
                if(!st.empty()) st.pop();
                else if(!st1.empty()) st1.pop();
                else return false;
            }
        }
        while(!st.empty() && !st1.empty()){
            if(st.top()>st1.top()) return false;
            st.pop();
            st1.pop();
        }
        return st.empty();
    }
};