class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        vector<vector<int>> vt;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto it : mp)
        {
            vt.push_back({it.first,it.second});
        }
        return vt;
    }
};