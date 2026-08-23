            N /=2;
        }
        return ans;
                ans *= x;
            x *=x;
        while(N>0)
        {
            if(N%2 == 1 )
            N = -1*N;
            x = 1/x;
        }
        double ans=1.0;
        {
        long long N = n;
        if(N<0)
class Solution {
public:
    double myPow(double x, int n) {
// got 100% beats
//note : look at ans not x the return is ans that value focus
//leet code :50. Pow(x, n)
//for SC 1