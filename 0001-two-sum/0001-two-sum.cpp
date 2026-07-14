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





/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> vt;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
                {
                    if(nums[i] + nums[j] == target)
                        {
                            vt.push_back(i);
                            vt.push_back(j);
                             return vt;
                        }
                }
        }
        return vt;
    }
};

*/