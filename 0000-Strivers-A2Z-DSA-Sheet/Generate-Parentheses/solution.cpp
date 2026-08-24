//not a leetcode problem
class Solution {
public:
    void solve(int n, int open, int close, string &curr, vector<string> &ans)
    {
        if(curr.size()== 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open < n)
        { 
            curr.push_back('(');
            solve(n, open+1, close, curr, ans);
            curr.pop_back();
        }
        if(close < open)
        {
            curr.push_back(')');
            solve(n, open, close+1, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        string s = "";
        solve(n, 0, 0, s, ans);
        return ans; 
    }
};