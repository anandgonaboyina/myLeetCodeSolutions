//my brute force solution got 100% beats
// this is the optimal solutin of TC N
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
        // dont do this as we just have to check the array size of 26 only that too frequency 
        // so count only no need to go for whole the length of the string and repeat the same comparasion
        /*
        for(int i=0; i<s.size(); i++)
        {
           if( hashArr1[s[i]-97] != hashArr2[s[i]-97] )
            return false;
        }
        */
        for(int i=0; i<26; i++)
        {
           if( hashArr1[i] != hashArr2[i] )
            return false;
        }
        return true;
    }
};