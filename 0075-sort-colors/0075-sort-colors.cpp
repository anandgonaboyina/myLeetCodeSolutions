// my brute force solution using selection sort
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i=0; i<n-1; i++)
        {
            int min = i;
            for(int j =i+1; j<n; j++)
            {
                if(nums[j]<nums[min])
                    min=j;
            }
            if(i != min)
                swap(nums[i], nums[min]);
        }
    }
    
};
