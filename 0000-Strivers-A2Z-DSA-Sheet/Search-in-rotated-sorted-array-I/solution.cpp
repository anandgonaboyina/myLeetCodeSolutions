//same problem from leetcode
//optimal solution
class Solution {
public:
    int findPivot(vector<int>&nums)
    {
        int n = nums.size();
        int left =0, right=n-1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right =mid;
        }
        return left;
    }

    int findInd(vector<int>&nums, int left, int right, int target)
    {
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(target==nums[mid])
                return mid;
            else if (target < nums[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int pInd = findPivot(nums);
        if(target>nums[n-1])
            return findInd(nums, 0, pInd-1, target);
        return findInd(nums, pInd, n-1, target);
    }
};

