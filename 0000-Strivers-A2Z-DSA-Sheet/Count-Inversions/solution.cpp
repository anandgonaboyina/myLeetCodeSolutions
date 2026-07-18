//similar follow up problem in leet code : 315. Count of Smaller Numbers After Self
//my brute force solution
class Solution {
public:
   long long int numberOfInversions(vector<int> nums) 
    {
        int n = nums.size();
        
    }
};

//from leetcode similar problem but asking total sum of array almost
/*
//my brute force solution passed 63/66 but still it can encounter the N^2 TLE
// when array is completely has distinct numbers
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n  = nums.size();
        if(n<2) return {0};
        vector<int> ans;
        int p=0;
        while(p<n)
        {
            int left = p+1, right=n-1;
            int cnt=0;
            while(left<=right)
            {
                if(nums[p]>nums[left])
                    cnt++;
                if(nums[p]>nums[right] && left !=right)
                    cnt++;
                left++; right--;
            }
            ans.push_back(cnt);
            p++;
            while(p<n && nums[p] == nums[p-1])
               {
                ans.push_back(cnt);
                p++;
               }
        }
        return ans;
    }
};

*/

// optimal solution  // need to complete this
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n  = nums.size();
        if(n<2) return {0};
        vector<int> ans;
        int p=0;
        while(p<n)
        {
            
            p++;
        }
        return ans;
    }
};

/*