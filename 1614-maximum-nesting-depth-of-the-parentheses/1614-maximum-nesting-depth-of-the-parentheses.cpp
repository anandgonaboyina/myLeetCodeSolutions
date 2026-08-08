//my brute force solution 100% beats with Tc is N and Sc is 1
class Solution {
public:
    int maxDepth(string s) {
        int maxCnt =0;
        int cnt =0;
        for(char ch : s)
        {
            if(ch == '(')
                {
                    cnt++;
                    maxCnt = max(maxCnt, cnt);
                }
            else if (ch == ')')
                {
                    cnt--;
                }
        }
        return maxCnt;
    }
};