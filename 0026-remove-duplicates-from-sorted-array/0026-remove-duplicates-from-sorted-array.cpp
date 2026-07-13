class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k=0, n=nums.size();
        if(n<2) return 1;
        for(int i=1; i<n; i++)
        {
            if(nums[k] != nums[i])
            {
                k++;
                nums[k]=nums[i];
            }
        }
        return k+1;
    }
};