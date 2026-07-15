class Solution {
public:
    int reverseNumber(int n) {
        int revN=0, num=n;
        while(num>0)
        {
            int ld = num%10;
            num=num/10;
            revN =revN*10 + ld;
        }
        return revN;
    }
};














