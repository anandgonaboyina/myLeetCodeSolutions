
class Solution {
public:
    int trailingZeroes(int n) {
        int num = n;
        int ans=0;
        pair<int, int> p={0,0};
        while(num !=0)
        {
            int x = num;
            while(x % 2 ==0)
            {
                p.first++;
                x /= 2;
            }
            while(x % 5 ==0)
            {
                p.second++;
                x /= 5;
            }
           num -= 1;
        }
        ans = min(p.first, p.second);
        return ans;
    }
};