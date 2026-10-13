    }
};


//leetcode all int
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true; 
        
        int num = x;
        long long revNum = 0;
        
        while(num != 0) {
            revNum = revNum * 10 + num % 10;
            num /= 10;
        }
        
        return revNum == x;
    }
};
/*
REVISION NOTES: PALINDROME NUMBER (LEETCODE 9)

1. Edge Cases:
   - Negative numbers are NEVER palindromes (e.g., -121 != 121-).
*/
   - Single-digit positive numbers (0-9) are ALWAYS palindromes.

2. The Overflow Bypass:
   - Reversing a massive 32-bit integer can cause overflow. 
   - Since the problem just asks for a boolean true/false, using 'long long' for revNum safely holds the reversed 
   number without needing the complex INT_MAX/INT_MIN checks.

Time Complexity: O(log10(N))
Space Complexity: O(1)
Note: If an insanely strict interviewer says "You are not allowed to use long long", the backup trick is to only 

reverse the right half of the number and check if it matches the left half