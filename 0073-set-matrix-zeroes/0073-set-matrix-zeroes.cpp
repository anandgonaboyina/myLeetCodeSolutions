//my brute force solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> zeroRows, zeroCols;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                    {
                        zeroRows.push_back(i);
                        zeroCols.push_back(j);
                    }
            }
        }
        int k = zeroRows.size();
        for(int i=0; i<k; i++)
        {
            matrix[zeroRows[i]] = vector<int>(n, 0);
            for(int j=0; j<m; j++)
            {
                matrix[j][zeroCols[i]]=0;
            }
        }
    }
};