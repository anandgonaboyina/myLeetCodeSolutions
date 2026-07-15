class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string st = "";
        for(int i=0; i<strs[0].length(); i++)
        {
            for(int j=0; j<strs.size(); j++)
            {
                if(strs[j][i] != strs[0][i])
                    return st;
            }
                st = st + strs[0][i];
        }
        return st;
    }
};
//anand kumar