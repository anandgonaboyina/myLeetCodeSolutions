//leetcode problem : 8. String to Integer (atoi) 
//my brute force solution  got 100 beats as Tc is N and Sc is 1
// this is optimal solution
class Solution {
public:
    int myAtoi(string s) {
        long long ans =0;
        bool isNeg = false;
        int intMax = (1LL<<31)-1;   // use INT_MAX, INT_MIN built in leetcode varibles
        int digitInd =0;
        while(digitInd < s.size() && s[digitInd] == ' ')
             digitInd++;
        if(digitInd < s.size() && s[digitInd] == '-')
            {
                digitInd++;
                isNeg = true;
            }
        else if(digitInd < s.size() && s[digitInd] == '+')
            digitInd++;
        for(int i=digitInd; i<s.size(); i++)
        {
            int n = s[i]-'0';
            if(n >= 0 && n <= 9)
                {
                    if(ans*10 + n >= intMax)
                        return intMax;
                    else if (ans*10 - n <= INT_MIN)
                        return INT_MIN;
                    else if(isNeg)
                        ans = ans*10 - n;
                    else
                        ans = ans*10 + n;
                }
            else
                break;
        }
        return ans;
    }
};