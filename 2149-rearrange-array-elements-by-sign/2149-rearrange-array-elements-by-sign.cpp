//brute force solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> Pnums, Nnums;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
            {
                Pnums.push_back(nums[i]);
            }
            else
            {
                 Nnums.push_back(nums[i]);
            }
        }
        int p=0,q=0;
        for(int i=0; i<n; i++)
        {
            if(i%2 ==0)
                nums[i]=Pnums[p++];
            else
                nums[i]=Nnums[q++];
        }
        return nums;
    }
};


/*
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
    }
};
*/