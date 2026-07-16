//solution
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
///for The Counter-Clockwise Trick
/*
Do either one below:
Reverse every row first, then Transpose.
///////or
Transpose first, then Reverse every column (flip top-to-bottom instead of left-to-right).
*/