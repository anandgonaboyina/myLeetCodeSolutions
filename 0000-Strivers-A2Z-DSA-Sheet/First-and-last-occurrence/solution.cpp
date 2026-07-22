//leetcode problem
class Solution{
public:
    int firstInd(vector<int> &nums, int target)
    {
        int n=nums.size();
        int left=0, right=n-1;
        int ind = -1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(target<=nums[mid])
            {
                right=mid-1;
                if(target==nums[mid])
                    ind=mid;
            }
            else if(target > nums[mid])
            {
                left = mid+1;
            }
        }
        return ind;
    }
    int lastInd(vector<int> &nums, int target)
    {
        int n =nums.size();
        int left=0, right=n-1;
        int ind=-1;
        while(left<=right)
        {
            int mid = left + (right -left)/2;
            if(target>=nums[mid])
            {
                if(target==nums[mid])
                    ind=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n=nums.size();
        int left=0, right=n-1;
        int ind1 = firstInd(nums, target);
        if(ind1==-1) return {-1, -1};
        int ind2 = secondInd(nums, target)
        return {ind1, ind2};
        
    }
};