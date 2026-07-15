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
                nums[i]=Pnums[p++];
                i++;
                nums[i]=Nnums[q++];
        }
        return nums;
    }
};


// Optimal Approach to make it in single pass
/*
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n);
        int posInd=0, negInd=1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
            {
                ans[posInd]=nums[i];
                posInd +=2;
            }
            else
            {
                 ans[negInd] = nums[i];
                 negInd +=2;
            }
        }
        return ans;
    }
};

*/