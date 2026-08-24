//not a leetcode problem

class Solution {
public:
    void solve(int n, string curr, vector<string> &ans)
    {
        if(curr.size()==n)
        {
            ans.push_back(curr);
            return;
        }
        curr.apend('0');
        solve(n, curr, ans);
        curr.pop_back();
        if(curr.back != '1')
            curr.append('1');
        solve(n, curr, ans);
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        if(n==0) return ans;
        string bstr = "";
        ans = solve(n, s, ans);
        return ans;
    }
};
