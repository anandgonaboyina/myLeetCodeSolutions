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

//notes for above problem
/*
Because you must generate every single combination (there is no target sum to bound you), the Pick / Not-Pick template is the mathematically optimal way to solve this. Your time complexity is a perfect $O(2^N)
=> One quick note: If the platform you are submitting to (like GeeksforGeeks) expects the final list of sums to be in increasing order, just add sort(ans.begin(), ans.end()); right before you return ans.
*/

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
