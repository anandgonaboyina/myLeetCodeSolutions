//leetcode problem
//got 100% beats
//my optimal approach
/*
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int twoNums =0;
        for(int x : nums)
        {
            twoNums ^= x;
        }
        int diffBit =0;
        for(int i=0; i<=31; i++)
        {
            if((twoNums>>i & 1)== 1)
            {
                diffBit = i;
                break;
            }
        }
        for(int i=0; i<=31; i++)
        {       
            int cnt =0; 
            for(int num : nums)
            {
                if((num>>i & 1 )== 1 && (num >> diffBit & 1 ) == 1)
                    cnt++;
            }
            if(cnt%2 == 1)
                ans[0] = ans[0] | (1U <<i);
        }
        ans[1] = twoNums^ans[0];
        return ans;
    }
};
*/
// Time Complexity: O(32 * N) -> simplifies to O(N), but with a slower constant factor.
// Space Complexity: O(1) auxiliary space.

//other way in minimized code
class Solution{
public:
    vector<int>  singleNumber(vector<int> &nums)
    {
        vector<int> ans(2, 0);
        long long twoNums =0;
        // Step 1: Get a ^ b
        for(int num : nums)
            twoNums ^= num;
        // Step 2: Find the rightmost bit where they differ.
        int diffBit=0;
        for(int i=0; i<32; i++)
        {
        if((twoNums>>i & 1 )== 1)
            {
                diffBit =i;
                break;
            }
        }
        // Step 3: Divide array into two buckets based on diffBit.
        // Duplicates always fall into the same bucket and cancel out to 0.
        for(int x : nums)
        {
            if((x>>diffBit & 1 )== 1)
                ans[0] ^= x;
            else
                ans[1] ^= x;
        }
        return ans;
    }
}; 
// Time Complexity: O(N) -> Only 2 passes through the array. 100% Beats optimal speed.
// Space Complexity: O(1) auxiliary space.