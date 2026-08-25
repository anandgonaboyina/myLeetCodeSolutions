
class Solution {
public:
    void solve(string &digits, vector<string> &ans, string &mp, vector<string> &pad, int i)
    {
        if(i==digits.size())
        {
            ans.push_back(mp);
            return;
        }
        for(int j=0; j<pad[digits[i]-'0'].size(); j++)
        {
            mp.push_back(pad[digits[i]-'0'][j]);
            solve(digits, ans, mp, pad, i+1);
            mp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string mp;
        solve(digits, ans, mp, pad, 0);
        return ans;

    }
};