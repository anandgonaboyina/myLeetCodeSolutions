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

//Notes for solving: 
/*
Because almost every number appears twice, they naturally form pairs that sit on Even and Odd indices.

Look at this array: [1, 1, 2, 3, 3, 4, 4]

Before the single element: Pairs always start on an Even index. (e.g., nums[0] == nums[1])

The single element: Takes up exactly one spot, which will always be an Even index (index 2 is the number 2).

After the single element: Everything gets shifted by one space. Now, pairs start on an Odd index. (e.g., nums[3] == nums[4])

with Binary Search Strategy:
When you calculate mid, look at its matching partner. Are they sitting on an (Even, Odd) rhythm? If yes, the single element hasn't messed up the line yet — search right. If the rhythm is backward, the single element is already behind you — search left.
If mid lands on an odd index, just do mid-- to push it back to the start of the pair. Then, you only ever have to check one thing: does nums[mid] match nums[mid + 1]?
*/


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