//leetcode problem : 645 Set misMatch
//my burte force optimal solution
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        long long arrSum=0, sum=(long long)n*(n+1)/2;  
        // here 10^4 array size so int enough but 
        //if 10^5 sum aslo will get integer overflow
        long long arrSum2=0;
        long long sum2= (long long)n*(long long)(n+1)*(2*n+1)/6;
        for(int i=0; i<n; i++)
        {
            arrSum +=nums[i];
            arrSum2 += (long long)nums[i]*(long  long)nums[i];
        }
        int x=(sum2-arrSum2)/(sum-arrSum); // here x = missN + reapN as from sum have missN and arrSum have repeatN
        int missN =( x + (sum-arrSum) )/2;
        int reapN = x-missN;
        return {reapN, missN};
    }
};










////////////////////////////////////////////////////////////////////////////
// discarded solution partially passed with xor will see in future
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) 
//     {
//         int n=nums.size();
//         int xorN=0, xorG=0;
//         for(int i=0; i<n; i++)
//         {
//             xorN ^= i+1;
//             xorG ^= nums[i];
//             if((xorN ^ xorG) != 0)
//                 return {nums[i], (i+1)};
//         }
//         return {-1, -1};
//     }
// };

//discarded solution again few tests only passed due to unsorted arrays failed
/*
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size();
        int arrSum=0, sum = n*(n+1)/2;
        bool isDuplicate=false;
        int duplicate=0;
        for(int i=0; i<n; i++)
        {
            arrSum += nums[i];
            if(!isDuplicate && duplicate==nums[i])
            {
                isDuplicate=true;
            }
            if(!isDuplicate)
                duplicate = nums[i];
        }
        return {duplicate, duplicate+(sum-arrSum)};
    }
};
*/

