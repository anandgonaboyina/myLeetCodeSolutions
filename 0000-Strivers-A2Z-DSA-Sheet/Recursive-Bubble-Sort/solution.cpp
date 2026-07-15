class Solution {
public:

    void RecBubbleSort(vector<int> &nums, int n)
    {
        if(n<=1) return;
        bool swapped = false;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i]>nums[i+1])
                {
                    swap(nums[i], nums[i+1]);
                    swapped = true;
                }
        }
        if(!swapped) 
            return;
        RecBubbleSort(nums, n-1);
    }
    vector<int> bubbleSort(vector<int>& nums) {
        RecBubbleSort(nums, nums.size());
        return nums;
    }
};
