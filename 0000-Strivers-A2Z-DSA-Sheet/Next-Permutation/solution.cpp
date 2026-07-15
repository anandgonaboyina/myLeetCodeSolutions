class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<2) return;
        int i =n-2;
        while(nums[i]>=nums[i+1] )
        {
            if(i==0)
                return reverse(nums.begin(), nums.end());
            i--;
        }
        int j=n-1;
        while(nums[i]>=nums[j])
        {
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
        return;
    }
};

// logic used to get the next permituation is here
/*
[2, 1, 5, 4, 3, 0]. If you want to make the next slightly larger number sequence, you read it from right to left to find where the sequence stops increasing.
Step 1:
 Find the Break Point (The Dip)Walk backward from the end of the array. Find the very first element that is smaller than the element right next to it (nums[i] < nums[i+1]).In [2, 1, 5, 4, 3, 0], looking backward: 0 -> 3 -> 4 -> 5 is increasing. 
 Then suddenly, it dips at 1 because 1 < 5.Index of 1 is your Break Point.
 (Note: If you walk all the way backward and find no dip at all—like [5, 4, 3, 2, 1]—it means you are at the absolute last permutation. In that case, just reverse the whole array to wrap around to the first permutation and return!)
Step 2:
 Find the Next Best SwapYou need to replace that break-point element (1) with the next slightly larger number available to its right.Walk backward from the end of the array again. Find the first number that is strictly greater than your break-point number.In our example, walking backward, 3 is the first number greater than 1.
 Swap them! The array changes from [2, 1, 5, 4, 3, 0] to [2, 3, 5, 4, 1, 0].
Step 3:
 Minimize the TailRight now, the numbers after your swapped index ([5, 4, 1, 0]) are still in descending order, making that section as large as possible.To make this the immediate next permutation, you want that tail section to be as small as possible (ascending order).Because that tail is guaranteed to be sorted in reverse, you can convert it to ascending order by simply reversing everything to the right of your original break point.
 Reversing [5, 4, 1, 0] turns it into [0, 1, 4, 5].
 Final Result: [2, 3, 0, 1, 4, 5] 
*/