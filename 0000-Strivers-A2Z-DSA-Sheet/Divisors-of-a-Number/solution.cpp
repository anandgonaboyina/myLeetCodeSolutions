//brute force solution tc is N
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int>vt;
        for(int i=1; i<=n; i++)
            {
                if(n%i==0) vt.push_back(i);
            }
        return vt;
    }
};
// optimal solution to make tc to root(N)
//since the smaller divisor in a pair will never exceed sqrt(n)
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int>vt;
        for(int i=1; i*i<=n; i++)
            {
                if(n%i==0)
                {
                    vt.push_back(i);
                    if(i*i != n)
                        vt.push_back(n/i);
                }
            }
            sort(vt.begin(), vt.end());
        return vt;
    }
};