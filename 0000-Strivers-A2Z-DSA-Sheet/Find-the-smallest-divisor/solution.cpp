//similar problem leetcode problem : 35 Search Insert Position
//just modification of it means dont return index of target if found that sit;
class Solution{
public:
    int upperBound(vector<int> &nums, int x)
    {
        int n = nums.size();
        int left=0, right=n-1;
        int ans=n;   // if no num found size of array
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(x < nums[mid])
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
};


