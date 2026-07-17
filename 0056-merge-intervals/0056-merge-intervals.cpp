class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<vector<int>> nums =intervals;
        for(int i=0;i<n; i++)
        {
        if(i<n-1 && nums[i][1]>=nums[i+1][0])
        {
            nums[i+1][0]=nums[i][0];
            if(nums[i][1]>nums[i+1][1])
            {
                nums[i+1][1]=nums[i][1];
            }
        }
        else
        ans.push_back(nums[i]);
        }
        return ans;
    }
};