//my brute force solution got 100% beats though it not a binary solution
//TC is M*N 
//by finding the first max element index in a row so left and right will garuntee smaller than it
//later checking the up and down elements with border checking first so we eleminate outer bounder cross
/*
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
*/
//optimal solution with TC as MlogN
// by first going to middle column and there row wise search for maxRow in that as it was already max in Column
// so need to check left and right to decide the peak
// decide which side will have max then increment left or dicrement right with mid reference by checking the boundary
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        int left=0, right = n-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int maxRow = 0;
            for(int i=0; i<m; i++)
            {
                maxRow = mat[maxRow][mid] > mat[i][mid] ? maxRow : i;
            }
            int leftNum = (mid > 0)? mat[maxRow][mid-1] : -1;
            int rightNum = (mid < n-1)? mat[maxRow][mid+1]: -1;
            if(mat[maxRow][mid]>leftNum && mat[maxRow][mid]>rightNum)
                return {maxRow, mid};
            else if(mat[maxRow][mid] < leftNum)
                right = mid-1;
            else
                left = mid+1;
        }
        return {-1, -1};
    }
};

