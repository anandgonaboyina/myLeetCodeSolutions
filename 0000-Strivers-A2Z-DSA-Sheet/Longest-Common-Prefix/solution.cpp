// leetcode problem : 14. Longest Common Prefix
//my optimal solution come from brute solution

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int right =0;
        for(int i=0; i<strs[0].length(); i++)
        {
            for(int j=0; j<strs.size(); j++)
            {
                if(i >= strs[j].length() ||  strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
                right++;
        }
        return strs[0].substr(0, right);
    }
};

// its optimal solution
//my brute force solution Tc is N^2 as i blindly used the string s : strs it copies each strs so makes take much time
/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int right=0;
        for(int i=0; i<strs[0].size(); i++)
        {
            for(string s : strs)
            {
                if(i >=s.size() || s[i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
                right++;
        }
        return strs[0].substr(0, right);
    }
};

*/

