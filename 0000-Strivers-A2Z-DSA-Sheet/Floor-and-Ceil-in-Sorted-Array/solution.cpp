//my optimal binary search solution
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) 
    {
        int n = nums.size();
        int left = 0, right=n-1;
        vector<int> ans(2);
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(x  == nums[mid])
                return {nums[mid], nums[mid]};
            else if (x < nums[mid])
            {
                ans[1] = nums[mid];
                right = mid-1;
            }
            else
            {
                left = mid+1;
                ans[0]=nums[mid];
            }
        }
        return ans;
    }
};