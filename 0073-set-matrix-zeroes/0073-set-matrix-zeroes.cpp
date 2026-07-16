//my brute force solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> zeroRows, zeroCols;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                    {
                        zeroRows.insert(i);
                        zeroCols.insert(j);
                    }
            }
        }
        int k = zeroRows.size();
        for(int row : zeroRows)
        {
            matrix[row] = vector<int>(n, 0);
        }
            for(int col : zeroCols)
            {
                for(int i=0; i<m; i++)
                    matrix[i][col]=0;
            }
        
    }
};