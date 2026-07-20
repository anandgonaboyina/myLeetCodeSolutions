// my brute force solution using selection sort
/*
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

*/
// optimal solution by using the dutch national flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high) 
        {
            if(nums[mid]==0)
                {
                    swap(nums[low], nums[mid]);
                    low++;mid++;
                }
            else if(nums[mid]==2)
                {
                    swap(nums[mid], nums[high]);
                    high--;
                }
            else
                {
                    mid++;
                }
        }
    }
};

