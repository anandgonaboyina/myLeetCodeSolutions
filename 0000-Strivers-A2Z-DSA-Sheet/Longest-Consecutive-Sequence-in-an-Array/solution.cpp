//my brute force
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n = nums.size();
        if(n<2) return n;
        unordered_map<int, int> mp;
        int maxL=1;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]=0;
        }
        // for(int x : nums)   //gives time limit exceed if array contains many no of
        //duplicates as we go on iterate each number if i use this so i go to unique those are 
        //keys here for maps
        for(auto x : mp)
        {
            if(mp.find(x.first-1) == mp.end())
                {
                    int k =x.first+1;
                    while(mp.find(k) != mp.end())
                        {
                        k++;                            
                        }
                        maxL = max(k-x.first, maxL);
                }
        }
        return maxL;
    }
};
*/
// my better approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n = nums.size();
        if(n<2) return n;
        unordered_set<int> st(nums.begin(), nums.end());
        int maxL=0;
        for(auto x : st)
        {
            if(!st.count(x-1))
                {
                    int length=1;
                    int nextN=x+1;
                    while(st.count(nextN))
                    {
                        length++;
                        nextN++;
                    }
                        maxL = max(length, maxL);
                }
        }
        return maxL;
    }
};