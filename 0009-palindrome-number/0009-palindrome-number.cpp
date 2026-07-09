class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x <10) return true;
        int num =x; long long revNum=0;
        while(num>0)
        {
            revNum = revNum*10 + num%10;
            num /=10;
        }
        return revNum == x;
    }
};