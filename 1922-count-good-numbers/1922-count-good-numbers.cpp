class Solution {
public:
    long long modPow(long long x, long long n)
    {
        long long ans = 1;
        long long MOD = 1e9 + 7;
        while(n>0)
        {
            if(n%2 == 1)
                ans = (ans*x)%MOD;
            x = (x*x)%MOD;
            n /=2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long evenInd = n%2==0? n/2 : n/2 + 1;
        long long oddInd = n/2;
        long long MOD = 1e9 +7;
        long long ans = 1;
        long long evens = modPow(5, evenInd)%MOD;   // {0, 2, 4,. 6, 8} => 5
        long long primes = modPow(4, oddInd)%MOD;   // {2, 3,. 5, 7}  => 4
        ans = (evens*primes)%MOD;   
        return ans;
    }
};