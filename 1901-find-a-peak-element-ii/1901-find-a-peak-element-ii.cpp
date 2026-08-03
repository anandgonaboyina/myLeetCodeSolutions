//my brute force solution
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n=mat[0].size();
        for(int i=0; i<m; i++)
            {
                int peak = 0;
                for(int j=0; j<n; j++)
                    {
                        peak = mat[i][peak]>mat[i][j]? peak: j;
                    };
                if( (i==m-1 || mat[i][peak]>mat[i+1][peak] ) && (i==0 || mat[i][peak] > mat[i-1][peak]))
                    return {i, peak};
            }
                return {-1, -1};
            
    }
};


/*
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        
    }
};

*/