//optimal solution obtained from finding the minimum number in distant nums
class Solution {
public:
    int findMinInd(vector<int>&nums)
    {
        int left=0, right=nums.size()-1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right=mid;
        }
    return left;
    }
    int findKRotation(vector<int> &nums)
    {
        int noRot = findMinInd(nums);
        //as no of right rotations = index of the first that is minimum number
        return noRot;
    }
};