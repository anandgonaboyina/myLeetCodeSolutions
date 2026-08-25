//notes to revise
/*
void solve(int n, string current_string, vector<string>& ans) {
    // 1. Base case: if current_string length == n, push to ans and return
    
    // 2. Choice 1: Always append '0' and call solve()
    
    // 3. Choice 2: If valid, append '1' and call solve()
}
*/
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

//notes to revise
/*
void solve(int n, string current_string, vector<string>& ans) {
    // 1. Base case: if current_string length == n, push to ans and return
    // 2. Choice 1: Always append '0' and call solve()
    // 3. Choice 2: If valid, append '1' and call solve()
}
*/
