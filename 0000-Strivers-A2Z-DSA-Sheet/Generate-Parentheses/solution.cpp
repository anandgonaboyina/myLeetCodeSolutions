            curr.pop_back();
            solve(n, open, close+1, curr, ans);
            curr.push_back(')');
        {
        }
        if(close < open)
            curr.pop_back();
            solve(n, open+1, close, curr, ans);
            curr.push_back('(');
        { 
        if(open < n)
            ans.push_back(curr);
            return;
        }
        if(curr.size()== 2*n)
        {
public:
    void solve(int n, int open, int close, string &curr, vector<string> &ans)
    {
class Solution {