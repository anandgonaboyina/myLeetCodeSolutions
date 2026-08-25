class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &vt, int k, int n, int sum , int i)
    {
        if(i ==10)
        {
            if(k==vt.size() && sum == n)
                ans.push_back(vt);
            return;
        }
        if(sum+i <= n && vt.size() < k)
        {
            vt.push_back(i);
            solve(ans, vt, k, n, sum+i, i+1);
            vt.pop_back();
        }
        solve(ans, vt, k, n, sum, i+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vt;
        solve(ans, vt, k, n, 0, 1);
        return ans;
    }
};