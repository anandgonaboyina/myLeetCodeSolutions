//my brute force
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
        // for(int x : nums)
        for(auto x : mp)
        {
            if(mp.find(x.first-1) == mp.end())
                {
                    int k =x.first+1;
                    while(mp.find(k) != mp.end())
                        {
                        maxL = max(k-x.first+1, maxL);
                        k++;                            
                        }
                }
        }
        return maxL;
    }
};