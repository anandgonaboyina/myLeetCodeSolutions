//optimal solution
class Solution {
public:
int findMinInd(vector<int>&nums, int target)
    {
        int n = nums.size();
        int left=0, right=n-1;
        while(left < right && nums[left]==nums[right])
            left++;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
                left = mid+1;
            else if(nums[mid]==nums[right])
                right--;
            else
                right=mid;
        }
        return left;
    }
    bool findInd(vector<int> &nums, int left, int right, int target)
    {
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(target == nums[mid])
                return true;
            else if(target < nums[mid])   // to clear the flat line form by duplicates
                right=mid-1;
            else
                left=mid+1;
        }
        return false;
    }

    bool search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int minInd = findMinInd(nums, target);
        if(target>nums[n-1])
            return findInd(nums, 0, minInd-1, target);
        else
        return findInd(nums, minInd, n-1, target);
    }
};