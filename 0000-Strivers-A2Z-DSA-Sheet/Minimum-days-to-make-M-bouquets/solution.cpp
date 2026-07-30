//leetcode problem : 704 binary search
//my brute force solution is optimal solution
//iterative method
/*
class Solution {
public:
    int search(vector<int>& nums, int target)
     {
        int n = nums.size();
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;   
            // (left+right)/2; may give integer overflow for 32 bit if array size if large 
            // before divison happen
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                right=mid-1
            else
                left=mid+1;
        }
        return -1;
    }
};

*/

//recursive method
class Solution {
public:
    int bSearch(vector<int>&nums, int left, int right, int target)
    {
        if(left>right) return -1;
        int mid = left + (right-left)/2;
        if(target==nums[mid])
            return mid;
        else if(target<nums[mid])
            return bSearch(nums, left, mid-1, target);
        else
            return bSearch(nums, mid+1, right, target);
    }

    int search(vector<int>& nums, int target)
     {
        int n = nums.size();
            int res = bSearch(nums, 0, n-1, target);
        return res;
    } 
};


