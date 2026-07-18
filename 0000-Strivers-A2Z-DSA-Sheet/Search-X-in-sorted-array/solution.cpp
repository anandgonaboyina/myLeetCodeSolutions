//leetcode problem : 704 binary search
//my brute force solution is optimal solution
//iterative method
/*
class Solution {
public:
    int search(vector<int>& nums, int target)
     {
        int n = nums.size();
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            int m =   i + (j-i)/2;
            // (i+j)/2; may give integer overflow for 32 bit if array size if large before divison happen
            if(nums[m]== target)
                return m;
            else if(target>nums[m])
                i=m+1;
            else if(target<nums[m])
                j=m-1;
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