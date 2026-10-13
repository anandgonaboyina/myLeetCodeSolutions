class Solution {
public:
    int reverse(int x) {
        int num = x;
        int revNum =0;
        while(num != 0)
        {
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10 )
                return 0;
            revNum = revNum*10 + num%10;
            num /= 10;
        }
        return revNum;
    }
};
//100% beats
// Time Complexity: O(log10(N))
// Space Complexity: O(1)

/*
REVISION NOTES: REVERSE INTEGER

1. The C++ Negative Modulo Trick:
   - C++ modulo handles negatives naturally: -12 % 10 = -2.
   - We don't need abs(x). Just use 'while(x != 0)'.

2. The Overflow Check:
   - We must check for overflow BEFORE multiplying by 10.
   - If revNum > INT_MAX / 10, then revNum * 10 will overflow.
   - If revNum < INT_MIN / 10, then revNum * 10 will underflow.
*/