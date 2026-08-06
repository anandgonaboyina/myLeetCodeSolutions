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






// old solution 
/*
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


*/