//leetcode : 20. Valid Parentheses
//got 100% beats SC is N and TC is N 
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n==0) return true;
        stack<char> st;
        for(char x : s)
        {
            if(x == '(' || x == '{' || x == '[')
                st.push(x);
            else
            {
                if(st.empty())
                    return false;
                if( (x == ')' &&  st.top() == '(') || (x == ']' &&  st.top() == '[') || (x == '}' &&  st.top() == '{') )
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};


/*
REVISION NOTES: VALID PARENTHESES

1. Why Two-Pointers (l < r) Fails:
   - Two pointers check for palindromes (e.g., "((...))").
   - It fails on sequential valid brackets like "()[]{}" because the left and right ends do not always relate to each other.

2. Why a Stack is Perfect:
   - Brackets follow a "Last Opened, First Closed" (LIFO) rule.
   - Every closing bracket MUST match the most recently opened bracket, which sits exactly at the top of a stack.

3. Common Traps to Avoid:
   - Segfaults: Calling st.top() on an empty stack crashes the program. Always check if(st.empty()) before checking the top.
   - Logic Flow: Group the logic using 'if / else'. If you use independent 'if' statements, a newly pushed opening bracket might immediately fall into the closing logic and return false.
   - Leftover Brackets: Don't just return 'true' at the end. An input like "((" will finish the loop successfully but is invalid. Always return st.empty() to ensure all brackets were closed.

Time Complexity: O(N) -> We traverse the string exactly once.
Space Complexity: O(N) -> In the worst case (e.g., "((((("), the stack holds N elements.
*/
