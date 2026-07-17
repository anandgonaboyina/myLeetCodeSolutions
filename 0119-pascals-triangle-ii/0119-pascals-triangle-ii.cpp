class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> pasTri;
        for(int i=0; i<=rowIndex; i++)
        {
            vector<int> row(i+1, 1);
            pasTri.push_back(row);
            for(int j=1; j<i; j++)
            {
                pasTri[i][j] = pasTri[i-1][j-1] + pasTri[i-1][j];
            }
        }
        return pasTri[rowIndex];
    }
};