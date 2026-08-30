//leetcode : 78. Subsets
class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<(1<<n); i++)
        {
        vector<int> sb;
            for(int j=0; j<n; j++)
            {
                if((i>>j & 1) == 1)
                    sb.push_back(nums[j]);
            }
        ans.push_back(sb);
        }
        return ans;
    }
};
// Time Complexity: O(2^N * N) -> Outer loop runs 2^N times, inner checks N bits.
// Space Complexity: O(1) -> Auxiliary space is constant (excluding the final answer array).