
// my brute force solution wihtout binary search so time limit exceed
/*

class Solution {
public:
    int checkSpeed(vector<int>& piles, int h, int k)
    {
        int khrs=0;
        for(int x : piles)
        {
            int pile=x;
            while(pile>0)
               {
                 pile = pile-k;
                 khrs++;
                 if(khrs>h)
                    return 0;
               }
        }
        if(khrs<=h)
            return 1;
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxPile=INT_MIN;
        int k;
        for(int x : piles)
        {
            maxPile = max(maxPile, x);
        }
        for(k=1; k<=maxPile; k++)
        {
            int isEnough = checkSpeed(piles, h, k);
            if(isEnough==1)
                return k;
        }
    return -1;
    }
};


*/

// optimal solution using binary search
class Solution {
public:
    long long calHours(vector<int>&piles, int k)
    {
        long long hrs=0;
        for(int pile : piles)
        {
            hrs += pile/k;
            if(pile%k != 0)
                hrs = hrs+1;
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left=1, right=0;
        for(int x : piles)
        {
            right = max(right, x);
        }
        int ans = right;
        while(left<=right)
        {
            int k = left+ (right-left)/2;
            long long reqHours = calHours(piles, k);
            if(reqHours <= h)
                {
                    ans = k;
                    right = k-1;
                }
            else
                left = k+1;
        }
        return ans;
    }
};