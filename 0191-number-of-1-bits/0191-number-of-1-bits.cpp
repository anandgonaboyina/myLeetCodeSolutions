//iterative way
// got 100% beats
/*
class Solution {
public:
    int hammingWeight(int n) {
        int num =n;
        int cnt = 0;
        while(num>0)
        {
            num = num & (num-1);
            cnt++;
        }
        return cnt;
    }
};
*/
class Solution {
public:
    int hammingWeight(int n) {
        if(n==0) return 0;
        if((n & (n-1)) == 0) return 1;
        return 1 + hammingWeight(n & (n-1));
    }
};