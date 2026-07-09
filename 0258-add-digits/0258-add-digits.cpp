class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        int n =num; int sum;
        do{
            sum =0;
            while(n>0)
            {
                sum =sum+ n%10; n=n/10;
            }
            n=sum;
        }while(n>=10);
        return n;
    }
};