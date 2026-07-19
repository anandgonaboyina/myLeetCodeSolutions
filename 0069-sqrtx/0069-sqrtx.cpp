//brute force solution
/*
class Solution {
public:
    int mySqrt(int x) 
    {
        int ans=0;
        for(int i=1; (long long)i*i<=x; i++)
        {
            ans = i;
        }
        return ans;
    }
};

*/
//optimal solution with binary search


class Solution {
public:
    int mySqrt(int x)
    {
        int left=0, right=x;
        int ans=0;
        while(left<=right)
            {
              int  mid = left + (right-left)/2;
                if((long long)mid*mid <= x)
                    {
                        left = mid+1;
                        ans = mid;
                    }
                else
                    right = mid-1;
            }
        return ans;
    }
};