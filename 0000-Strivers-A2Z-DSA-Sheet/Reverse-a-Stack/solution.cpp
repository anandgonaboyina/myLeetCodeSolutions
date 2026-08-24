// not a leetcode problem
//runs in O(N^2) time and O(N) space, which is exactly the optimal solution for recursive constraint
class Solution {
public:
    void helper(stack<int> &st, int ele)
    {
        if(st.empty())
        {
            st.push(ele);
            return;
        }
        int t = st.top();
        st.pop();
        helper(st, ele);
        st.push(t);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        int t = st.top();
        st.pop();
        reverseStack(st);
        helper(st, t);
    }
};

/*
One function to empty the stack (the Unpacker).
A helper function to insert the held element at the very bottom of the stack (the Organizer). 
*/