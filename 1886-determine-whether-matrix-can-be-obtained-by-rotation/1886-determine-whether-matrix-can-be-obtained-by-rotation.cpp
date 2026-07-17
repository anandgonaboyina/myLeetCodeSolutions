class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        int n= mat.size();
        int rotCnt=0; bool eql=true;
        while(rotCnt<4)
        {
    /*
        eql=true;
        for(int i=0; i<n; i++)
        {    
            for(int j=0; j<n; j++)
                if(mat[i][j] != target[i][j])
                    {
                        eql=false;
                        break;
                    }
        }
        if(eql) return true;
    */
        /// OR AS Cpp can do direct comparision with == element wise for vectors
        if(mat==target) return true;

        for(int i=0; i<n; i++)
        {   for(int j=i+1; j<n; j++)
                swap(mat[i][j], mat[j][i]);
            reverse(mat[i].begin(), mat[i].end());
        }
        rotCnt++;
        }
        return false;
    }
};