//leet code problem  : 1539. Kth Missing Positive Number
//  brute force solution beats 100% but not logN tc
/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int kth = k;
        for(int x : arr)
        {
            if(x<=kth)
                kth++;
            else
                break;
        }
        return kth;
    }
};
*/
// optimal binary solution so tc is logN
//need to get some clarity here in this question
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int left=0, right=arr.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int missingNums = arr[mid]-(mid+1);
            if(missingNums < k)
                left= mid+1;
            else
                right = mid-1;
        }
        return left+k;
    }
};

//brute force and optimal binary solution explanation
/*
The Missing Number Formula
In a perfect array with no missing numbers, the value at any index i is exactly i + 1.

Index 0 should be 1

Index 1 should be 2

Index 2 should be 3

If the actual number at arr[i] is larger than i + 1, the difference tells you exactly how many numbers are missing before that index.
Formula: missing = arr[i] - (i + 1)

Example: arr = [2, 3, 4, 7, 11]
Look at index 3 (the number 7):

It should be 3 + 1 = 4.

It is 7.

7 - 4 = 3. There are exactly 3 missing numbers before the number 7.

The Binary Search Setup
You apply binary search on the indexes (left = 0, right = n - 1), not the numbers themselves.

For every mid:

Calculate missing = arr[mid] - (mid + 1).

If missing < k: You haven't skipped enough numbers yet. Search right (left = mid + 1).

If missing >= k: You skipped too many numbers. Search left (right = mid - 1).

When the loop breaks, left will be exactly one step ahead of right.
The math beautifully simplifies, and your final answer to return is always exactly left + k.
*/