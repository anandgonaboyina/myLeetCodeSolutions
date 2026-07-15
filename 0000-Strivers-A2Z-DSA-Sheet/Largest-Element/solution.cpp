class Solution {
public:
    int largestElement(vector<int>& nums) {
        int large = nums[0];
        for(int x : nums)
        {
            if(x>large)
            {
                large = x;
            }
        }
        return large;
    }
};