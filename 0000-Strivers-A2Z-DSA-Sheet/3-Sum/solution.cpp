// my brute force solution
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        set <vector<int>> ans;
        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
        {
            if(i != j && i != k && j !=k && nums[i]+nums[j]+nums[k]==0)
               { 
                vector <int> triplet={nums[i], nums[j], nums[k]};
                sort(triplet.begin(), triplet.end());
                ans.insert(triplet);
                }
        }
        }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
*/
//optimal approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue; // skiping the duplicate value
            int left = i+1, right=n-1;
            while(left < right)
        {   int sum=nums[i]+nums[left]+nums[right];                        
            if(sum<0)
               {
                    left++;
               }
            else if(sum>0)
                right--;
            else
                {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++; right--;
                while(left < right && nums[left] == nums[left-1])
                left++;
                while(left<right &&  nums[right] == nums[right+1])
                right--;
                }
        }
        }
        return ans;
    }
};
