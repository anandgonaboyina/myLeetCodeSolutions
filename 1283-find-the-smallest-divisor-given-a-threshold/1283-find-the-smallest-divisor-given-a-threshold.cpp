//optimal solution again adopted form previous koko eating bananas problem pattern
class Solution {
public:
    int calDivSum(vector<int>&nums, int div)
    {
        long long sum=0;
        for(int x : nums)
        {
            sum += x/div;
            if(x%div !=0)
                sum++;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int left=1, right=0;
        for(int x : nums)
            right = max(right, x);
        int ans = right;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int sum = calDivSum(nums, mid);
            if(sum<= threshold)
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