//my brute force solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1; j<n; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int left=j+1, right=n-1;
                while(left<right)
                {
                    long long sum = (long long)(nums[i]) +nums[j]+nums[left]+nums[right];
                    if(sum-target < 0)
                        left++;
                    else if(sum-target > 0)
                        right--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                        while(left<right && nums[left]==nums[left-1])
                            left++;
                        while(left<right && nums[right]==nums[right+1])
                            right--;
                    }
                }
            }
        }
        return ans;
    }
};
















//previously solved solution
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        int n = nums.size();
           for(int i=0; i<n; i++)
           {
                if(i>0 && nums[i]==nums[i-1])
                    continue;
                for(int j=i+1; j<n; j++)
                {
                    if(j>i+1 && nums[j] == nums[j-1])
                        continue;
                    int left =j+1, right = n-1;
                        while(left < right)
                            {
                                long long current_sum =  (long long)nums[left]+ nums[right] + nums[i] + nums[j];
                                if(current_sum < target)
                                    left++;
                                else if(current_sum > target)
                                    right--;
                                else 
                                    {
                                        sol.push_back({nums[i], nums[j], nums[left], nums[right]});
                                        while(left<right && nums[left] == nums[left+1]) 
                                            left++;
                                        while(left<right && nums[right] == nums[right-1])
                                            right--;
                                        left++; right--;
                                    }
                            }
                }
 
           }
        return sol;
                
    }
};

*/

////////////////////////////////////////////////


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) 
//     {
//         vector<vector<int>> sol;
//         int n = nums.size();
//            for(int i=0; i<n; i++)
//            {
//                 for(int j=i; j<n; j++)
//                 {
//                     vector<int> temp;
//                    if(nums[i]+nums[j]+nums[n-1-i]+nums[n-1-j]==target && !(nums[i]==nums[j]==nums[n-1-i]==nums[n-1-j]))  
//                     {       temp.push_back(nums[i]);
//                             temp.push_back(nums[j]);
//                             temp.push_back(nums[n-1-i]);
//                             temp.push_back(nums[n-1-j]);
//                             sol.push_back(temp);
//                     }

//                 }
 
//            }
//         return sol;
                
//     }
// };