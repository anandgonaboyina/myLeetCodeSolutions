//my brute force solution not binary solution as they didnt metnions it is sorted rows
// this is the optimal brute force solution

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        vector<int> ans(2, 0);
        for(int i=0; i< mat.size(); i++)
        {
            int cnt=0;
            for(int j=0; j<mat[0].size(); j++)
            {
                cnt += mat[i][j];
            }
           if(ans[1]< cnt)
                {
                    ans = {i, cnt};
                }
        }
        return ans;
    }
};


// optimal binary solution  for sorted rows fails for unsorted rows here it failed at 179/1049 tests passed
/*
class Solution {
  public:   
  vector<int> rowAndMaximumOnes(vector <vector< int >> & mat) 
  {
    int n = mat[0].size();
    vector<int> ans(2, 0); 
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
                    if(ans[1] < n-mid)
                    {
                        ans = {i, n-mid};
                    }
                }
                else
                    left = mid+1;
            }
    }
    return ans;
  }
};

*/