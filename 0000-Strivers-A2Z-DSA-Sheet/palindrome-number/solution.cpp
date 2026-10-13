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
       num /= 10;
    }
    return revNUm == n;
    long long revNum =0;
    while(num != 0)
    {
       revNum = revNum*10 + num%10;
public:
    bool isPalindrome(int n) {
    int num =n;
class Solution {