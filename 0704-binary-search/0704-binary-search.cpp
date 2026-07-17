//my brute force solution is optimal solution
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