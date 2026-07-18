//leetcode problem : 35 Search Insert Position
// class Solution{
// public:
//     int lowerBound(vector<int> &nums, int x)
//     {
        
//     }
// };

//my brute force solution is optimal solution
class Solution {
public:
    int lowerBound(vector<int>& nums, int target)
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
        return -1; //to skip compilation error
    }
};