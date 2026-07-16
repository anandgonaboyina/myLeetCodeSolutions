//my brute force solution
/*
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
    int n=nums.size();
      if(n<2) return nums;
      vector<int> ans;
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
            ans.push_back(nums[i]);
      }
      return ans;
    }
};
*/

//my Optimal approach

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n=nums.size();
      if(n<2) return nums;
      int maxN=INT_MIN;
      vector<int> ans; int n=nums.size();
      for(int i=n-1; i>=0; i--)
      {
        if(nums[i]>maxN )
        {
            maxN =max(nums[i], maxN);
            ans.push_back(nums[i]);
        }
      };
      reverse(ans.begin(), ans.end());
      return ans;
      }
    };

