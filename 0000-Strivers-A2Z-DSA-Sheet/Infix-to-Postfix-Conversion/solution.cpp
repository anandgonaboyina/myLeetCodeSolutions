//not leetcode problem
// not completed need to finish this 
class Solution {
public:
    string infixToPostfix(string s) {
       string ans="";
       stack<char> st;  // for holding the operands
       for(char x : s)
       {
            if(x == '(')
            {
                st.push(x);
            }
            else if(x == ')')
            {
                st.pop();
                while(!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else if(x == '+' || x == '-')
            {
                while(!st.empty() && st.top() == '^')
                {
                    ans += st.top();
                    st.pop();
                }
                while(!st.empty() && st.top() == '*' || st.top() == '/')
                {
                    ans += st.top();
                    st.pop();
                }
                while(!st.empty() && st.top() == '-' || st.top() == '+')
                {
                    ans += st.top();
                    st.pop();
                }
                st.push();
            }
            else if(x == '*' || x == '/')
            {
                while(!st.empty() && st.top() == '^')
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(x);
            }
            else
                ans += x;
       }
       while(!st.empty())
       {
        ans += st.top();
        st.pop();
       }
       return ans;
    }
};