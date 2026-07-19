// my  optimal solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int left=0, right = nums.size()-1;
            while(left<right)
            {
                int mid = left + (right-left)/2;
                if(mid%2 == 1)
                    mid--;
                if(nums[mid]==nums[mid+1])
                    left = mid +2;
                else 
                    right = mid;
            }
            return nums[left];
    }
};




// not a binary search just one of the search for unsorted array

/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int xorN = 0;
        for(int x : nums)
        {
            xorN ^= x;
        }
        return xorN;
    }
};
*/