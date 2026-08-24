//notLeetCode problem.
// It is a classic GeeksforGeeks / Coding Ninjas problem.
class Solution {
public:
    void insertSorted(stack<int> &st, int ele)
    {
        if(st.empty() || ele > st.top())
        {
            st.push(ele);
            return;
        }
        int t = st.top();
        st.pop();
        insertSorted(st, ele);
        st.push(t);

    }
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int t = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, t);
    }
};