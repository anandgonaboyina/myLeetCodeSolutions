};
// Time Complexity: O(log10(N))
// Space Complexity: O(1)

// LeetCode 7: Reverse Integer 
//here range is total int n so not same as below it will crash if we reverse an maxInt
class Solution {
public:
    int reverse(int x) {
        int num = x;
        int revNum =0;
        while(num != 0)
        {
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10 )
                return 0;
            revNum = revNum*10 + num%10;
            num /= 10;
        }
        return revNum;
    }
    
//100% beats
// Time Complexity: O(log10(N))
// Space Complexity: O(1)

/*
/*
*/
        }
        return revNum
    }
        while(num >0)
        {
            revNum = 10*revNum + num%10;
            num /= 10;
    int reverseNumber(int n) {
        int num = n;
        int revNum =0;
//for n >=0 and n<=5000
class Solution {
public: