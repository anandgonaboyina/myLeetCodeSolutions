//my brute force solution

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

// optimal solution will see later not done yet
/*
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        <vector<int>row(0, 1);
        if(rowIndex==0) return row;
        for(int i=1; i<=rowIndex; i++)
        {
            for(int j=i-1; j>0; j++)
            {
                row[j] = row[j-1] + pasTri[i-1][j];
            }
        }
        return row;
    }
};
*/