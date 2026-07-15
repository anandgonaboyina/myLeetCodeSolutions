//brute force
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {   
        int sum=0, n=nums.size();
        int maxSum=INT_MIN;
        for(int i=0; i<n; i++)
        {
            sum=0;
            for(int j=i;j<n; j++ )
            {
                sum +=nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};
*/
///////////////////////////////////////////////////////
// Optimal approach
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum=INT_MIN, sum=0;
        for(int x : nums)
        {
            sum +=x;
            maxSum = max(maxSum, sum);
            if(sum<0)
                sum=0;
        }
        return maxSum;
    }
};

*/
/////////////////////////////////////////////////////////////
//FOR Returning the subArray that has maximum sum

class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) 
    {
        int sum=0, maxSum=INT_MIN;
        vector<int> vt;
        for(int x : nums)
        {
            sum +=x;
            maxSum = max(maxSum, sum);
            if(sum<0)
            {
                sum=0;
            }
            vt.push_back(x);
        }
    }
};
//anand
