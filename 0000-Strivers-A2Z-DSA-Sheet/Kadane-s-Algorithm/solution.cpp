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

#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

class Solution {
public:
    std::vector<int> maxSubArray(std::vector<int>& nums) 
    {
        int sum = 0, maxSum = INT_MIN;
        int startIn = 0;
        std::pair<int, int> subArrInd = {0, 0}; 
        
        for(int i = 0; i < nums.size();  i++)
        {
            sum += nums[i];
            maxSum = std::max(maxSum, sum);
            if(sum == maxSum) 
            {
                subArrInd = {startIn, i};
            }
            if(sum < 0)
            {
                sum = 0;
                startIn = i + 1;
            }
        }
        
        return std::vector<int>(nums.begin() + subArrInd.first, nums.begin() + subArrInd.second + 1);
    }
};

//
