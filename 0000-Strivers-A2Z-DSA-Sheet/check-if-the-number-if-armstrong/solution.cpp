    int noDigits = floor(log10(n)) +1;
    while(num != 0)
    int num =n;
    {
    }
    }
    long long sum = 0;
        num /= 10;
    return armN == n;
    if(n<0) return false;
};
/*
REVISION NOTES: ARMSTRONG NUMBERS
here max of the 32bit int the longest digits are 10 only that is log10N max is only 10 so square is 100 operations 
1. The Definition:
   - An Armstrong number (n) equals the sum of its digits each raised to the power of the total number of digits.
   - Example: 153 has 3 digits. 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153.
   - Strictly positive. Negatives return false.

2. The Overflow Trap:

   - For a 10-digit number, we might calculate 9^10. 
   - 9^10 = 3,486,784,401, which exceeds the 32-bit INT_MAX (2,147,483,647 ~= 2*10^9).
   - Use 'long long' for the sum and power calculations to bypass overflow instantly.
        int digit = num %10;
        for(int i=0; i<noDigits; i++)
        {
            if(sum + powerValue > n) return false;
        }
        long long powerValue = 1;
            powerValue *= digit;
only so this is the optimized
//
//
Time Complexity : O((log10(N))^2)
since,  O(log10(N)) for digits * O(log10(N)) for power = O((log10(N))^2)
Space Complexity: O(1)

*/ 