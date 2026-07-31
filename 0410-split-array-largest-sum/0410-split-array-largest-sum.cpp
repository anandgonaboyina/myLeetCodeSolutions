
//brute force solution

// optimal bianry solution TC is N*log2(S) where  s= right-left;
class Solution {
public:
    bool checkSubArrys(vector<int> &nums, int k, int maxSum)
    {
        int cnt =1, sum=0;
        for(int x : nums)
        {
            if(sum + x > maxSum)
            {
                cnt++;
                sum=x;
            }
            else
                sum += x;
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n<k) return -1;
        int left=0, right=0;
        for(int x : nums)
        {
            left = max(left, x);
            right += x;
        }
        int ans= -1;
        if(n==k) return left;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(checkSubArrys(nums, k, mid))
                {
                    ans = mid;
                    right = mid-1;
                }
            else
                left = mid+1;
        }
        return ans;
    }
};