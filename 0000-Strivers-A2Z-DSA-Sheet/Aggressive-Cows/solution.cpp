// no leet code problem but in code ninja / greeks for greeks
class Solution {
public:
    bool checkMinDis(vector<int>&nums, int k, int dis)
    {
        int noCows=1;
        int lastPlacedCow =nums[0];
        for(int i=1; i<nums.size(); i++)
            {
                if(nums[i]-lastPlacedCow >= dis)
                    {
                        noCows++;
                        lastPlacedCow = nums[i];
                    }
            }
            return noCows >= k;
    }

    int aggressiveCows(vector<int> &nums, int k) 
    {
        sort(nums.begin(), nums.end());
       int left=1, right=nums.back()-nums[0];
       int ans = 1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            bool isEnoughDis = checkMinDis(nums, k, mid);
            if(isEnoughDis)
                {
                    ans = mid;
                    left = mid+1;
                }
            else
                right = mid-1;
        }
        return ans; 
    }
};