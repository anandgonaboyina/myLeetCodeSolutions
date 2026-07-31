// Question : 
/*
Every student must get at least one book.
Books must be distributed continuously (you cannot scramble the array order; you just place dividers between books to group them).
All books must be handed out.

The Goal: "Minimize the Maximum Burden"
Some students will inevitably get more pages than others. The problem asks you to find the arrangement where the student who has to read the most pages gets the smallest possible amount. You are trying to make the reading load as fair as possible.
*/

//brute force Solution  TC is N*S where S is right-left
public:
{
    int countStudents(vector<int> &nums, int maxP)
    {
        int cnt=1;
        int currentPages =0;
        for(int x : nums)
        {
            if(currentPages + x > maxP)
            {
                cnt++;
                currentPages = x;
            }
            else
                currentPages +=x;
        }
        return cnt;
    }

    int findPages(vector<int> &nums, int m)  
    {
        int n = nums.size();
        if(n<m) return -1;
        int left=1, right=0;

        for(int x : nums)
            {
                left = max(left, x);
                right += x;
            }

        if(n==m) return left;

        while(left<=right)
        {
            if(countStudents(nums, left) == m)
                break;
            left++;
        }
        return left;
    }
};



/*
Optimal binary solution TC is N*log2(S) where S = right - left
class Solution {
public:
    bool checkMaxPages(vector<int> &nums, int m, int Mpages)
    {
        int currentPages = nums[0];
        int noOfStd = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(currentPages + nums[i] > Mpages)
                {
                    currentPages = nums[i];
                    noOfStd++;
                }
            else
                currentPages += nums[i];
        }
        return noOfStd <= m;
    }
    int findPages(vector<int> &nums, int m)  
    {
        int n = nums.size();
        if(n<m) return -1;

        int maxPages = 0;
        int TotalPages=0;
        for(int x : nums)
        {
            maxPages =  max(maxPages, x);
            TotalPages += x;
        }

        if(n==m) return maxPages;

        int left = maxPages, right = TotalPages;
        int ans = -1;

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            bool isEnoughStudents = checkMaxPages(nums, m, mid);
            if(isEnoughStudents)
                {
                    ans = mid;
                    right = mid-1;
                }
            else 
                left = mid+1;
        }
        return ans;
    }
};

*/