//my brute force solution
/*
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
*/
//in above i used vectors those allows multiple same values of i and j so
//as no need to make the row again to zero vector as it takes time i used set to make it take unique i values not duplicate and for columns too 

//my better solution
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