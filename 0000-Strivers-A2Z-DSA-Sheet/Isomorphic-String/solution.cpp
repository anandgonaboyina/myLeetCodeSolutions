//leetcode problem : 205. Isomorphic Strings
//brute force solution  got 100 beats though SC is 2*N
class Solution {
public:
    bool isomorphicString(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            mp1[t[i]] = s[i];
        }
        for(int i=0; i<n; i++)
        {
            mp2[s[i]] = t[i];
        }
        for(int i=0; i<n; i++)
        {
            if(mp1[t[i]] != s[i] || mp2[s[i]] != t[i])
                return false;
        }
        return true;
    }
};