                return -1; 
            fact *= num;
            num -= 1;
        } 
        return fact;
    }
};

/*
REVISION NOTES: FACTORIAL

1. The Math Trap:
   - 0! = 1, and 1! = 1.
   - Do NOT return 'n' for small numbers! 4! is 24, not 4. 

2. The Overflow Check:
   - Factorials grow so fast that 13! exceeds the 32-bit INT_MAX.
   - Checking `fact > INT_MAX / num` BEFORE multiplying perfectly catches this.

3. Recursion Space:
   - Recursion takes O(N) Auxiliary Space due to the call stack. Iterative is O(1) space.
*/
// Time Complexity: O(N)
// Space Complexity: O(1)

/*
//recursively

class Solution {
public:
    int factorial(int n) {
        while(num > 0 )
        {
            if(fact > INT_MAX/num)
    int factorial(int n) {
        if(n == 0 || n == 1) return 1;
        int fact =1;
        int num =n;
//Leetcode similar problem : 172. Factorial Trailing Zeroes
class Solution {
public: