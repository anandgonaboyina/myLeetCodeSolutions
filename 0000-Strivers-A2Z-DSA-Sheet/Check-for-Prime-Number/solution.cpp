//optimal Solution from divisors method
// as divisors of a number is never exceed square root and bigger will get from n/i;
class Solution {
public:
    bool isPrime(int n) {
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++)
            {
                if(n%i==0)
                {
                    return false;
                }
            }
        return true;
    }
};