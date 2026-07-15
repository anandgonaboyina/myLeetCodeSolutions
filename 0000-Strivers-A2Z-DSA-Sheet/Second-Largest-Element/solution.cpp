class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
            if(nums.size()<2) return -1;
        int large=INT_MIN, slarge=INT_MIN;
        for(int x : nums)
        {
            if(x>large)
            {
                slarge = large;
                large =x;
            }
            else if(x<large && slarge<x)
            {
                slarge =x;
            }
        }
        return slarge==INT_MIN? -1 : slarge;
    }
};