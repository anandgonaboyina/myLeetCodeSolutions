class Solution {
public:
    bool isPalindrome(int n) {
        int num=n, revNum=0;
        while(num>0)
        {
            revNum = revNum*10 + num%10;
            num = num/10;
        }
        return n==revNum;
    }
};