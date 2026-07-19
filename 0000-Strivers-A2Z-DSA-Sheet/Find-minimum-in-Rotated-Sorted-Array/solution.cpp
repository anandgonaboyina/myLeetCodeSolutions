//leet code problem
class Solution {
public:
    int findMinInd(vector<int>&nums)
    {
        int left = 0, right=nums.size()-1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
                left = mid+1;
            else
                right=mid;
        }
    return left;
    }

    int findMin(vector<int> &nums)  
    {
        int minInd = findMinInd(nums);
        return nums[minInd];
    }
};