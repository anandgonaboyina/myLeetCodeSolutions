//got 100% beats
// Tc is 32N == 32N and SC is 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        vector<int> freq(31, 0);
        for(int i=0; i<=31; i++)
        {
        int cnt =0;
        for(int num : nums)
           {
            if((num >>i & 1) == 1)
                cnt++;
           }
           if(cnt%3 == 1 )
                ans = ans | (1<<i);
        }
        return ans;
    }
};