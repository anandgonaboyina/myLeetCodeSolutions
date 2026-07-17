// my brute force solution
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        int n = numRows;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            vector<int> row(i+1, 1);
            ans.push_back(row);
            for(int j=1; j<i; j++)
                {
                    ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
                }
        }
        return ans;
    }
};