//my solution adopted from previous rotated search problem fucntion just find the starting index of the nums
class Solution {
public:
    int findPivot(vector<int> &nums)
    {
        int n = nums.size();
        int left=0, right=n-1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        int minIndex = findPivot(nums);
        return nums[minIndex];
    }
};