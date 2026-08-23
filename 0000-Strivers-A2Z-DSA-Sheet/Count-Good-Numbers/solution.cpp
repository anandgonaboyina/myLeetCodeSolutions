//optimal solution
//got 100% beats
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


/*
========================================= 
REVISION NOTES: COUNT GOOD NUMBERS
=========================================
1. The Built-in `pow()` Trap:
   - Never use `pow()` for massive integers or modulo problems. It uses floating-point math and loses precision. 
   - FIX: Write your own Modular Binary Exponentiation function.

2. The Modulo Trap:
   - When calculating (A * B) % MOD, you must apply the modulo to the intermediate steps to prevent overflow: 
     ans = ((ans % MOD) * (base % MOD)) % MOD. 

3. Type Safety:
   - Always use `long long` for intermediate answers when multiplying modulo values, otherwise `int * int` might overflow before the modulo can catch it.
*/ 