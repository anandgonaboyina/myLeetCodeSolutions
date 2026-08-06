//my brute force solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int right=0;
        for(int i=0; i<strs[0].size(); i++)
        {
            for(string s : strs)
            {
                if(s[i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
                right++;
        }
        return strs[0].substr(0, right);
    }
};
