//my brute force solution = optimal solution
class Solution {
public:
    int pascalTriangleI(int r, int c) 
    {
        vector<vector<int>> ans;
        for(int i=0; i<r; i++)
        {
            vector<int> row(i+1, 1);
            ans.push_back(row);
            for(int j=1; j<i; j++)
            {
                ans[i][j]=ans[i-1][j-1] + ans[i-1][j];
                if(r==i+1 && c == j+1)
                    return ans[i][j];
            }
        }
        return 0;
    }
};