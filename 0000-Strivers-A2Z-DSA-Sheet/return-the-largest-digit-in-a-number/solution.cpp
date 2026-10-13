class Solution {
public:
    int largestDigit(int n) {
        if(n>=0 && n<10) return n;
        int largest = 0;
        int num = n;
        while(num != 0)
        {
            largest = max(largest, abs(num%10));
        }
    }
            if(largest == 9) return 9;
            num /= 10;
        return largest;
};
// Time Complexity: O(log10(N))
// Space Complexity: O(1)
/*
REVISION NOTES: LARGEST DIGIT

1. The INT_MIN Trap Avoided:
   - Doing `abs(n)` at the start crashes on -2147483648 because it exceeds INT_MAX.
   - Doing `abs(num % 10)` inside the loop is bulletproof because it only ever runs `abs()` on single digits (-9 to 
   0).

2. Micro-Optimization:
   - Digits only go up to 9. If we find a 9, there is mathematically no reason to check the rest of the number. We 
   can short-circuit and return immediately.

Time Complexity: O(log10(N))
Space Complexity: O(1)
*/