// brute force without constant extra space
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

/// my Better Approach
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