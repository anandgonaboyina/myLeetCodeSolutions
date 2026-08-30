//using the recursion
//got 100% beats
/*
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
// Time Complexity: O(2^N * N) -> 2^N total subsets, and copying each to 'ans' takes O(N) time.
// Space Complexity: O(N) -> Maximum recursion tree depth is N.  since log2(2^N) => N

//better approach to make SC to 1
// Approach 2: Bit Manipulation (The Binary Checklist)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<(1<<n); i++)
        {
        vector<int> sub;
            for(int j=0; j<n; j++)
            {
                if((i>>j & 1) == 1)
                    sub.push_back(nums[j]);
            }
        ans.push_back(sub);
        }
        return ans;
    }
};
// Time Complexity: O(2^N * N) -> Outer loop runs 2^N times, inner checks N bits.
// Space Complexity: O(1) -> Auxiliary space is constant (excluding the final answer array).