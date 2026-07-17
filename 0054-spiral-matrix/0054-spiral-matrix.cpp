class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m<2) return matrix[0];
        // if(m==2)
        // {
        //     vector<int>ans;
        //     ans.insert(ans.end(), matrix[0].begin(), matrix[0].end());
        //     ans.insert(ans.end(), matrix[1].begin(), matrix[1].end());
        //     return ans;
        // }
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