//for n >=0 and n<=5000
public:
    int reverseNumber(int n) {
        int num = n;
        int revNum =0;
        while(num >0)
        {
            revNum = 10*revNum + num%10;
        }
    }
            num /= 10;
};
// Time Complexity: O(log10(N))
class Solution {
        return revNum
// Space Complexity: O(1)