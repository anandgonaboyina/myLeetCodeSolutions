//my Brute force solution
/*
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
*/
/////////////////////////////////////////////////////////////////////
//////////////if array is sorted we can use two pointer approach
// as we know if new element is bigger or smaller
// we can get extra space as 1 with tc N

// Better Approach for unsorted array tc is N
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
                return {mp[target-nums[i]], i};
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
*/


//here in this problem we need to return orginial indexes so dont use if you want check below 
//method we used vector<pair<int,int>>; to store original indexes

//Optimal Approach by sorting the array first and applying the two pointer approach
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int left=0, right=n-1;
            while(left<right)
            {
                int sum = nums[left] + nums[right];
                if(sum>target)
                {
                    right--;
                }
                else if(sum<target)
                {
                    left++;
                }
                else
                return {left, right};
            }
            return {-1, -1};
    }
};
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<pair<int, int>> indexedNums(n);   
         // vector pairs {element_value, original_index}
        for (int i = 0; i < n; i++) {
            indexedNums[i] = {nums[i], i};
        }
        
        // pairs sort by first element by default s
        sort(indexedNums.begin(), indexedNums.end());
        
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;  
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                return {indexedNums[left].second, indexedNums[right].second};
            }
        }
        
        return {-1, -1};
    }
};
