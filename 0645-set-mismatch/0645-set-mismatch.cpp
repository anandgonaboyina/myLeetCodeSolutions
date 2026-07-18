//better solution //need to complete will see later
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size();
        int arrSum=0, sum=n*(n+1)/2;
        long long arrSum2=0;
        long long sum2= (long long)n*(n+1)*(2*n+1)/6;
        for(int i=0; i<n; i++)
        {
            arrSum +=nums[i];
            arrSum2 +=nums[i]*nums[i];
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

