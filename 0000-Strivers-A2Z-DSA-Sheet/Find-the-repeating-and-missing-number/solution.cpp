//leetcode problem : 645 Set misMatch
//my burte force optimal solution
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) 
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