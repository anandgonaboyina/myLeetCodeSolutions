class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &vt, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(vt);
            return;
        }
        vt.push_back(nums[i]);
        solve(nums, ans, vt, i+1);
        vt.pop_back();
        int curr = i;
        while(i+1 < nums.size() && nums[curr] == nums[i+1])
            i++;
        solve(nums, ans, vt, i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vt;
        sort(nums.begin(), nums.end());
        solve(nums, ans, vt, 0);
        return ans;
    }
};