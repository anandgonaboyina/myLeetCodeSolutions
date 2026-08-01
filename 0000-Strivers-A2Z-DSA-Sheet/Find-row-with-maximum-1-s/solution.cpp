//leet code problem : 2643. Row With Maximum Ones
// in leetcode  not mentioned as sorted so brute force is optimal solution
//optimal brute force Solution
/*
public:
    int rowWithMax1s(vector<vector<int>>& mat) 
    {
        int ans =0;
        for(int i=0; i< mat.size(); i++)
        {
            int cnt=0;
            for(int j=0; j<mat[0].size(); j++)
            {
                cnt += mat[i][j];
            }
           if(ans< cnt)
                {
                    ans = i;
                }
        }
        return ans;
    }
};
*/
// optimal binary solution 
class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) 
  {
    int n = mat[0].size();
    int ans= -1; 
    int cnt =0;
    for(int i=0; i<mat.size(); i++)
    {
        if(mat[i][n-1]==0)
            continue;
        int left=0, right=n-1;
            while(left <=right)
            {
                int mid = left + (right-left)/2;
                if(mat[i][mid]==1)
                {
                    right = mid-1;
                    if(cnt < n-mid)
                    {
                        ans = i;
                        cnt = n-mid;
                    }
                }
                else
                    left = mid+1;
            }
    }
    return ans;
  }
};