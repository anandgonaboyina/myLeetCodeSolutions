//not a leetcode problem

class Solution {
public:
    void solve(int n, string &curr, vector<string> &ans)
    {
        if(curr.size()==n)
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back('0');
        solve(n, curr, ans);
        curr.pop_back();
        if(curr.empty() || curr.back() != '1')
        {
            curr.push_back('1');
            solve(n, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        if(n==0) return ans;
        string bstr = "";
        solve(n, bstr, ans);
        return ans;
    }
};
