
// one line bit manipulation math trick
/*
A power of two in binary always has exactly one 1 bit (e.g., 4 is 100, 8 is 1000).
If you subtract 1 from a power of two, it flips that 1 and all the 0s after it (e.g., 4 - 1 = 3, which is 011).

Because of this, doing a bitwise AND (&) between n and n - 1 will always equal 0 if the number is a power of two:
100 & 011 == 000
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n & (n-1) ) == 0;
    }
};

//old approach
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n ==1 )
        return true;
        if(n ==0 || n%2 !=0)
        return false;
        else
            return isPowerOfTwo(n/2);
    }
};
*/

//discarded appraoch as A^B == A only if B==0 but the ~(1<<lastBit) never 0 so fails
//using bit manipilation approach
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int lastBit = 0;
        int num =n;
        while(num > 1)
        {
            num = num/2;
            lastBit++;
        }
        return (n ^ ~(1<<lastBit)) == n;
    }
};
*/