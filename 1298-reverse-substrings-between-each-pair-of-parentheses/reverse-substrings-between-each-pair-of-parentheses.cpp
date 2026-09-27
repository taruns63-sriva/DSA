class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        vector<char> res;

        for(char ch : s)
        {
            if(ch == '(')
            {
                st.push(res.size());
            }
            else if(ch == ')')
            {
                int temp = st.top();
                st.pop();
                reverse(res.begin() + temp, res.end());
            }
            else
            {
                res.push_back(ch);
            }
        }
        return string(res.begin(), res.end());
    }
};