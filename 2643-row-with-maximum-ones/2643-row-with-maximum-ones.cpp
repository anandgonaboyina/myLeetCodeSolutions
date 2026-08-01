//my brute force solution not binary solution
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        vector<int> ans(2, 0);
        for(int i=0; i< mat.size(); i++)
        {
            int cnt=0;
            for(int j=0; j<mat[0].size(); j++)
            {
                cnt += mat[i][j];
            }
           if(ans[1]< cnt)
                {
                    ans = {i, cnt};
                }
        }
        return ans;
    }
};