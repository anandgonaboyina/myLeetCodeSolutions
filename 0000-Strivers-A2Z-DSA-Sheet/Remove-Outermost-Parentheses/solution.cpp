//my brute force solution got 100% beats
class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string ans;
        int cnt=0;
        for(char ch : s)
            {
                if(ch == '(')
                    {
                        cnt++;
                        if(cnt != 1)
                            ans += ch;
                    }
                else if(ch == ')')
                    {
                        cnt--;
                        if(cnt !=0)
                            ans +=ch;
                    }
            }
            return ans;
    }
};