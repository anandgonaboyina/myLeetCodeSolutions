//my brute force solution
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
        return -1;
    }
};