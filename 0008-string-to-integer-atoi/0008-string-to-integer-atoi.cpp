//my brute force solution  got 100 beats as Tc is N and Sc is 1
// this is optimal solution but not minimized code
/*
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

*/
//revision 1
//BETTER THAN FIRST APPROACH
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1;
        int i=0;
        int n = s.size();
        while(i<n && s[i]==' ')
            i++;
        if(i<n && (s[i] == '-' || s[i]=='+'))
        {
            sign = s[i]=='-'? -1:1;
            i++;
        }
        while(i<n  && (s[i] >= '0'&& s[i] <= '9'))
        {
            ans = ans*10 + (s[i]-'0');
            i++;
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            if(sign ==-1 && -ans < INT_MIN) return INT_MIN;
        }
        //not best way to write this much length below
        // ans = (ans>INT_MIN && ans <INT_MAX)? ans : (ans <= INT_MIN? INT_MIN : INT_MAX);
        return ans*sign;
    }
};
/*
=========================================
REVISION NOTES: String to Integer (myAtoi)
=========================================
1. The Leading Character Trap:
   - ONLY skip spaces (' '). If you hit a letter or other symbol first, stop.
   
2. The String vs. Char Typo:
   - MISTAKE: s <= '9' (comparing a whole string to a char).
   - FIX: Always use the index: s[i] <= '9'.

3. The ">" vs ">=" Logic (Why no = symbol):
   - If ans is exactly INT_MAX (2147483647), it is a perfectly VALID integer.
   - If you use `>=`, you wrongly intercept and cap a valid maximum number.
   - FIX: Only trigger the overflow cap if it STRICTLY EXCEEDS the limit (> or <).

4. The Negative Overflow Sign Trap:
   - MISTAKE: if (sign == -1 && ans < INT_MIN)
   - WHY IT FAILS: 'ans' is accumulated as a positive number (e.g., 2147483648). A positive number is never mathematically smaller than INT_MIN (-2147483648).
   - FIX: Apply the negative sign to ans 
   during the check: if (sign == -1 && -ans < INT_MIN).

5. Catch Overflow Inside the Loop:
   - A 30-digit string will overflow even a 'long long' if you wait until the loop finishes. 
   - Always check boundaries on the fly inside the while loop.
*/