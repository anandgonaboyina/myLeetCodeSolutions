// binary search solution
/*
class Solution {
public:
    int firstInd(vector<int> &nums, int target)
    {
        int left = 0, right= nums.size()-1;
        int first=-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(target == nums[mid])
            {
                first = mid;
                right = mid-1;
            }
            else if (target < nums[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        return first;
    }

    int lastInd(vector<int>&nums, int target)
    {
        int left=0, right = nums.size()-1;
        int last = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(target == nums[mid])
            {
                last = mid;
                left = mid+1;
            }
            else if(target < nums[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        return last;
    }

vector<int> searchRange(vector<int>& nums, int target) 
    {
        int first = firstInd(nums, target);
        if(first == -1) return {-1, -1};
        int last = lastInd(nums, target);
        return {first, last};
    }
};



*/

//my brute force solution discarded
//discarded solution as if more than two duplicates there it fails 
//though it passed 63/66 tests but not reliable not a solution
/*
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n= nums.size();
        int left=0, right=n-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(target == nums[mid])
            {
                
                while(target == nums[])
                    return {mid-1, mid};
                else if(mid != n-1 && target == nums[mid+1])
                    return {mid, mid+1};
                else
                    return {mid, mid};
            }
            else if(target < nums[mid])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }

        }
        return {-1, -1};
    }
};

*/


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
        return ind;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n=nums.size();
        int left=0, right=n-1;
        int ind1 = firstInd(nums, target);
        if(ind1==-1) return {-1, -1};
        int ind2 = lastInd(nums, target);
        return {ind1, ind2};
        
    }
};