//for SC 1
// got 100% beats
//note : look at ans not x the return is ans that value focus
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N<0)
        {
            N = -1*N;
            x = 1/x;
        }
        double ans=1.0;
        while(N>0)
        {
            if(N%2 == 1 )
                ans *= x;
            x *=x;
            N /=2;
        }
        return ans;
    }

};

//revise 1
//slightly modified code but same approach to achive SC as log2N due to recursive calls of binary division and TC also Log2N
//but "old" way (using long long N = n) is actually the industry standard.
/*
Here is why: in production engineering, readability beats cleverness. Casting to a 64-bit integer (long long) takes zero extra execution time, uses practically zero extra memory, and allows other engineers to understand your code instantly without doing mental algebra of that INT_Min safety thing
*/
/*
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        else if(n<0)
            return (1/(x*myPow(x, -1*(n+1)) ));  
            // n+1 to avoid the INT_MIN convertion > INT_MAX and for compensate it just multiply wtih x in denominator
        double half = myPow(x, n/2);
        if(n%2 == 0) return half*half;
        return half*half*x;
    }
};
*/

//intial old approach
/*
class Solution {
public:
    double myPow(double x, int n) {
        long long N =n;
        return solve(x, N);
    }
    private :
    double solve(double x, long long n)
    {
        if(n<0)
                return 1/solve(x, -1*n);  // as here solve 2nd parameter is long long so INT_MIN can convert to INT_MAX in no time
        if(n==0)
            return 1;
        double half = solve(x, n/2);
        if(n%2 ==0)
            return half*half;
        else
            return half*half*x;
    }
};
*/