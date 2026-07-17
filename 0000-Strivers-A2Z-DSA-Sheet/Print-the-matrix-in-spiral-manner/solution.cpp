//my brute force solution  with 100% beats 
/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m<2) return matrix[0];
        vector<int>ans;
        int istart=0,jstart=0;
        while(true)
     {   vector<int>temp;
        for(int i=istart; i<m; i++)
        {
            if(i !=istart && i !=m-1 && jstart < n-1)
                temp.push_back(matrix[i][jstart]);
            for(int j=jstart; j<n; j++)
            {
                if(i==istart || j==n-1 || i==m-1)
                    ans.push_back(matrix[i][j]);
                
            }
                if(i==m-2)
                    {
                        reverse(matrix[m-1].begin(), matrix[m-1].end());
                    }
        }
        n=n-1; m=m-1;
        reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
        istart++; jstart++;
        if(istart > m) break;
     }
     return ans;
    }


};

*/
//above Input Mutation: we are using reverse() directly on matrix
//if we are not allowed to change the matrix as it asked to traversal but we used reversal on matirx and cant make copy as it increases space complexity
/*it was not good as it does these below things
Calling reverse() directly on the rows permanently alters the input matrix. If another part of the software needed to read that matrix after your function ran, it would read corrupted data.
Fragility: The dense block of nested if statements is very hard to maintain
*/
///////////////////////////////////////////////
//better approach
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m<2) return matrix[0];
        vector<int>ans;
        int top=0,bottom=m-1;
        int left=0,right=n-1;
        while(top<=bottom && left <=right)
     {   
        for(int i=left; i<=right; i++)
        {
                ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
        right--;
        if(top<=bottom)
        {   for(int i=right; i>=left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }
        if(left<=right)
        {   for(int i=bottom; i>=top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
     }
     return ans;
    }
};
