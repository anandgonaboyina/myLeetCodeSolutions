//got 100% beats
class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &vt, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(vt);
            return;
        }
        vt.push_back(nums[i]);
        solve(nums, ans, vt, i+1);
        vt.pop_back();
        solve(nums, ans, vt, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vt;
        solve(nums, ans, vt, 0);
        return ans;
    }
};