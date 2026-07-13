
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes =0;
        int n =nums.size(), k=0;
        while(k <n)
        {
            int cnt=0;
            while(k<n && nums[k] ==1)
            {
                k++; cnt++;
            }
            k++;
            maxOnes = max(maxOnes, cnt);
        }
        return maxOnes;
    }
};