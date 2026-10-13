// Time Complexity: O(N)

/*
    }
};
        }
                return -1;
            fact *= num;
            num -= 1;
        return fact;
// Space Complexity: O(1)

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
//recursively

class Solution {
public:
    int factorial(int n) {
        if(n == 0) return 1;
        return n * factorial(n-1);
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)

*/