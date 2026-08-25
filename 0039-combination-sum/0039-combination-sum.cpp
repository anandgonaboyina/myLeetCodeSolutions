//my optimal solution Tc is 2^n and Sc is n
//beats 100%
//here distinct nums given but for combination sum 2 it can contain duplicates so mind it as it wont give the unique combination
class Solution {
public:

    void solve(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &vt, int sum,  int i)
    {
        if(i==candidates.size())
        {
            if(sum==target)
                ans.push_back(vt);
            return;
        }
        if(sum+candidates[i] <= target)
        {   
            vt.push_back(candidates[i]);
            solve(candidates, target, ans, vt, sum+candidates[i], i);
            vt.pop_back();
        }
        solve(candidates, target, ans, vt, sum, i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vt;
        solve(candidates, target, ans, vt, 0, 0);
        return ans;
    }
};