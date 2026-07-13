
// brute force idea i got
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        int sum = n*(n+1)/2;
        int sum2=0;
        for(int x : nums)
        {
            sum2 +=x;
        }
        return sum-sum2;
    }
};
*/

// other approaches
/*
[Naive Approach] Linear Search for Missing Number - O(n^2) Time and O(1) Space
[Better Approach] Using Hashing - O(n) Time and O(n) Space
[Expected Approach 1] Using Sum of n terms Formula - O(n) Time and O(1) Space
[Expected Approach 2] Using XOR Operation - O(n) Time and O(1) Space
*/

//using the XOR operation
//theory used to solve this is
/*
Finding the Unique Element: In an array where every element appears twice except for one, XORing all elements together cancels out the duplicates (X ^ X = 0) and leaves the unique number.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1=0, x2=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            x1 ^= nums[i];
            x2 ^= (i+1);
        }
        return (x1 ^ x2);
        // this is leaving the missed number as it was not there
        // in x1 but all are there in x2
    }
};