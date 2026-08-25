class Solution{
    public:    	

    void solve(vector<int> &nums, int k,  int sum, int i, int &n)
    {
        if(i == nums.size())
            {
                if(sum == k)
                    n++;
                return;
            }
        solve(nums, k, sum+nums[i], i+1, n);
        solve(nums, k, sum, i+1, n);
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int n = 0;
        solve(nums, k, 0, 0, n);
        return n;
    }
};