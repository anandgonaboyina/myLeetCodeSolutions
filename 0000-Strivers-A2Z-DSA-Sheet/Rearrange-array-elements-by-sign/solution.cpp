//Brute force solution
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
        for(int j=i+1; j<n; j++)
        {
            if(nums[i]+nums[j]==target)
            return {i,j};
        }
        }
        return {-1,-1};
    }
};
*/
/////////////////////////////////////////////////////////////////////
//////////////if array is sorted we can use two pointer approach
// as we know if new element is bigger or smaller
// we can get extra space as 1 with tc N

// Better Approach for unsorted array tc is N
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
                return {mp[target-nums[i]], i};
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
