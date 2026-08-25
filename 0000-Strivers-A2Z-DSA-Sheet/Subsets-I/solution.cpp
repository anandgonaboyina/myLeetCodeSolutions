//similar leetcode problem but it asks direct subsets return
//78. Subsets
class Solution {
  public:
    void solve(vector<int> &nums, vector<int> &ans, int sum, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(sum);
            return;
        }
        solve(nums, ans, sum+nums[i], i+1);
        solve(nums, ans, sum, i+1);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        solve(nums, ans, 0, 0);
        return ans;
    }
};

//leetcode problem 78. Subsets
//similar leetcode problem but it asks to return direct vector of subsets
/*
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
*/
