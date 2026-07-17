class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int xorN = 0;
        for(int x : nums)
        {
            xorN ^= x;
        }
        return xorN;
    }
};