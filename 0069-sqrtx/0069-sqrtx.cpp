//brute force solution
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

//optimal solution with binary search