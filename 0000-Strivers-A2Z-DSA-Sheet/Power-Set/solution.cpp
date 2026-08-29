class Solution {
public:
    void solve(vector<int> &nums, vector<int> &pt, int i, vector<vector<int>> &ans)
    {
        if(i==nums.size())
        {
            ans.push_back(pt);
            return;
        }
        pt.push_back(nums[i]);
        solve(nums, pt, i+1, ans);
        pt.pop_back();
        solve(nums, pt, i+1, ans);
    }
    vector<vector<int> > powerSet(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n==0) return ans; // no need i think
        vector<int> pt;
        solve(nums, pt, 0, ans);
        return ans;
    }
};