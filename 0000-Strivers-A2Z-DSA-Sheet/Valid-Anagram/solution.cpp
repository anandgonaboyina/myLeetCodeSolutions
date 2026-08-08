
//brute force by comparing the each char after sorting both strings Tc is NlogN and Sc is 1 as sorting takes in element in place
/*
class Solution {
public:
    bool anagramStrings(string s, string t) {
        int n = s.size(), m = t.size();
        if(n !=m) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<n; i++)
            if(s[i] != t[i])
                return false;
        return true;
    }
};
*/
//my brute force solution got 100% beats as this is Optimal solution
// this is the optimal solutin of TC N and SC is 1 as fixed sized arrays are using irespective of size of string

class Solution {
public:
    bool anagramStrings(string s, string t) {
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
        // for(int i=0; i<s.size(); i++)
        // {
        //    if( hashArr1[s[i]-97] != hashArr2[s[i]-97] )
        //     return false;
        // }
        // better is below
        
        for(int i=0; i<26; i++)
        {
           if( hashArr1[i] != hashArr2[i] )
            return false;
        }
        return true;
    }
};

