class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxOnes =0;
        int n =nums.size(), cnt=0;
        for(int i=0; i<n; i++)
            {
                if(nums[i]==1)
                {
                    cnt++;
                    maxOnes = max(maxOnes, cnt);
                }
                else
                    cnt=0;
            }
        return maxOnes;
    }
};

