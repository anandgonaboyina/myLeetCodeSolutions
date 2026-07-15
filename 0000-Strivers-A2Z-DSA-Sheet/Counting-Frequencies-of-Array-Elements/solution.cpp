class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<vector<int>> vt;
        for(auto it : mp)
        {
            vt.push_back({it.first,it.second});
        }
        return vt;
    }
};