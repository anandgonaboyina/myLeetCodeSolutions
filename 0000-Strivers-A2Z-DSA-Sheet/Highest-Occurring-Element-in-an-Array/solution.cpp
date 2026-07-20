//optimal solution
class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        if(nums.empty()) return -1;
        unordered_map<int, int> mp;
        pair<int,int> maxCnt;
        maxCnt = {0,0};
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>maxCnt.second)
                maxCnt = {nums[i], mp[nums[i]]};
            else if(mp[nums[i]]==maxCnt.second && nums[i]<maxCnt.first)
                maxCnt = {nums[i], mp[nums[i]]};
        }

    return maxCnt.first;
    }
};

mp;
pair<int, int> maxCnt;
mp[nums[i]]++;
if mp[nums[i]]>maxCnt.second
  maxCnt = {nums[i], mp[nums]}
else mp[nums[i]]==maxCnt.second && nums[i]<maxCnt.first
  maxCnt = {nums[i], mp[nums]}


