//got 100% beats
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int twoNums =0;
        for(int x : nums)
        {
            twoNums ^= x;
        }
        int diffBit =0;
        for(int i=0; i<=31; i++)
        {
            if((twoNums>>i & 1)== 1)
            {
                diffBit = i;
                break;
            }
        }
        for(int i=0; i<=31; i++)
        {       
            int cnt =0; 
            for(int num : nums)
            {
                if((num>>i & 1 )== 1 && (num >> diffBit & 1 ) == 1)
                    cnt++;
            }
            if(cnt%2 == 1)
                ans[0] = ans[0] | 1<<i;
        }
        ans[1] = twoNums^ans[0];
        return ans;
    }
};