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














//old tried not done
/*

class Solution {
public:
    bool isValid(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r)
        {
            if((s[l] !=s[r])) 
                return false;
            l++; r--;
        }
        return true;
    }
};
*/