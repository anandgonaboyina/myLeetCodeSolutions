//bineary search solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int left=0, right=n-1;
        int ans;
        while(left<=right)
        {
            int mid = right + (left-right)/2;
            if(target==nums[mid])
                {
                    ans=mid; break;
                }
            else if(target<nums[mid])
                    {
                        right = mid-1; ans=mid;
                    }
            else if(target>nums[mid])
                {
                    left = mid+1; ans=left;
                }
        }
        return ans;
    }
};











//my brute force solution is leanear searcg solution => Not a binary search
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left=0, right=n-1;
        int p=0;
        while(p<n)
        {
            if(target==nums[left])
                return left;
            else if(target==nums[right])
                return right;
            else if(target<nums[left])
                return left;
            else if(target>nums[right])
                return right+1;
            else 
                {
                    left++; right--;
                }
            p++;
        }
        return -1; //just to skip compilation error
    }
};

*/