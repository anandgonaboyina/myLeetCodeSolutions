// Better approach using map hashing as array hashing cant use if negative numbers there or big sized numberes there;
/* 
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        for(int x : nums)
        {
            mp[x]++;
        }
        for(auto it : mp)
        {
            if(it.second==1) 
                return it.first;
        }
        return -1;
    }
};
*/

/// my Optimal Approach
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
       int n=0;
        for(int x : nums)
        {
            n ^= x;
        }
        return n;
    }
};

//brute force TC N^2
// we do search for occurance of a element using counter and another loop inside
// if only once appeared then we will return that