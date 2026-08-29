//leetcode : 191. Number of 1 Bits
//recursively
class Solution {
public:
    int countSetBits(int n) {
        if(n==0) return 0;
        if((n & (n-1)) == 0) return 1;
        return 1+countSetBits( n & (n-1));
        // n & (n-1) jumps directly to the next set bit
    }
};
//iteratively
/*
class Solution{
public:
    int countSetBits(int n)
    {
        int cnt =0;
        int num = n;
        while(num>0)
        {
            num = num & (num-1);
            cnt++;
        }
    }
};
*/