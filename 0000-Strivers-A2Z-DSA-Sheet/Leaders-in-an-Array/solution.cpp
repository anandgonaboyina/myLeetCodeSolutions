//my brute force solution
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      if(n<2) return nums;
      vector<int> ans; int n=nums.size();
      for(int i=0; i<n; i++)
      {
        bool isLeader = true;
        for(int j=i+1; j<n; j++)
        {
            if(nums[j]>nums[i])
                {
                    isLeader = false;
                    break;
                }
        }
        if(isLeader)
            ans.push(nums[i]);
      }
      return ans;
    }
};