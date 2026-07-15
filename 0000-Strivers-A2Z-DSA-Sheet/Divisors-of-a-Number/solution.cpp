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