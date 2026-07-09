class Solution {
public:
    bool isPalindrome(int x) {
        int num =x; long long revNum=0;
        while(num>0)
        {
            revNum = revNum*10 + num%10;
            num /=10;
        }
        return revNum == x;
    }
};