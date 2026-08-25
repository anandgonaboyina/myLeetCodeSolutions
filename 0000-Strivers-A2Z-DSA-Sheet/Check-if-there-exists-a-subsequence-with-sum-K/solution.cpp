//not a leetcode problem
class Solution{
    public:
    bool solve(vector<int> &nums, int k, int sum, int i)
    {
        if(i==nums.size())
        {
            if(sum==k)
                return true;
            return false;
        }
        return solve(nums, k, sum+nums[i], i+1) || solve(nums, k, sum, i+1);
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return solve(nums, k, 0, 0);
    }
};
