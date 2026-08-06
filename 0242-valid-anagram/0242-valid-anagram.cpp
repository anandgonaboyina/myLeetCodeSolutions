//my brute force solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> hashArr1(26, 0), hashArr2(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            hashArr1[s[i]-97]++;
        }
        for(int i=0; i<s.size(); i++)
        {
            hashArr2[t[i]-97]++;
        }
        for(int i=0; i<s.size(); i++)
        {
           if( hashArr1[s[i]-97] != hashArr2[s[i]-97] )
            return false;
        }
        return true;
    }
};