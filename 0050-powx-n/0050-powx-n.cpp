//revise 1
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        else if(n<0)
            return (1/(x*myPow(x, -1*(n+1)) ));  // n+1 to avoid the INT_MIN convertion > INT_MAX
        double half = myPow(x, n/2);
        if(n%2 == 0) return half*half;
        return half*half*x;
    }
};







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
            {
                return 1/solve(x, -1*n);
            }
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