//iterative way
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