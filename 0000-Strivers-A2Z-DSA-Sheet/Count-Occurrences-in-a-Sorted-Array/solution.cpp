// binary search solution optimal tc as logN
class Solution {
public:
    int firstInd(vector<int> &nums, int target)
    {
        int left = 0, right= nums.size()-1;
        int first=-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(target <= nums[mid])
            {
                if(target==nums[mid])
                    first = mid;
                right = mid-1;
            }
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
            if(target >= nums[mid])
            {
                if(target==nums[mid])
                    last = mid;
                left = mid+1;
            }
            else
                right = mid-1;
        }
        return last;
    }

    int countOccurrences(vector<int>& nums, int target) 
    {
        int first = firstInd(nums, target);
        if(first == -1) return 0;
        int last = lastInd(nums, target);
        return last-first+1;
    }
};


//brute force solution discarded
//discarded solution as it wont work it can skip few counts
/*
class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) 
    {
        int n = arr.size();
        int left =0, right = n-1;
        int cnt=0;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(target <= arr[mid])
            {
                if(target==arr[mid])
                    cnt++;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return cnt;
    }
};
*/