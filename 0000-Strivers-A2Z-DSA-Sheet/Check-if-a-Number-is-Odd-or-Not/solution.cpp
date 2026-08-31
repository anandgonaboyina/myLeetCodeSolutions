// class Solution {
// public:
//     bool isOdd(int n) {
//        return n%2 !=0; 
//     }
// };

// Bitwise AND 
class Solution {
public:
    bool isOdd(int n) {
       return n&1 == 1; // or // return n&1 !=0  or n%2 != 0
    }
};
