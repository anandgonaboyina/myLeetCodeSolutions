//leetcode problem : 35 Search Insert Position
// class Solution{
// public:
//     int lowerBound(vector<int> &nums, int x)
//     {
        
//     }
// };

//my brute force solution is optimal solution
class Solution {
public:
    int lowerBound(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left=0, right=n-1;
        int ans;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(target <= nums[mid])
                {
                    ans =mid;
                    right=mid-1;
                }
            else
                {
                    left=mid+1;
                    ans=mid+1;
                }
        }
        return ans;
    }
};