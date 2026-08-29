//got 94% beats
class Solution {
public:
    bool isPalindrome(string & s, int left, int right)
    {
        if(s.empty() || left >= right) return true;
        return s[left] == s[right] && isPalindrome(s, left+1, right-1);
    }
    void solve(string &s, vector<vector<string>> &ans, vector<string> &pt, int i)
    {
        if(i == s.size())
        {
            ans.push_back(pt);
            return;
        }
        for(int j=i; j<s.size(); j++)
        {
            if(isPalindrome(s, i, j))
            {
                string sub = s.substr(i, j-i+1);
                pt.push_back(sub);
                solve(s, ans, pt, j+1);
                pt.pop_back();
            }
        }
    }

    vector<vector<string>>partition(string s) {
        vector<vector<string>> ans;
        if(s.empty()) return ans;
        vector<string> pt;
        solve(s, ans, pt, 0);
        return ans;
    }
};