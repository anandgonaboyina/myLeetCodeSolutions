
// my brute force solution TC is N power 2 as sum of N nums steps takes 72/144 passed
// time limit exceed as reverse and substr takes N each insdie so N3 Tc
/*
class Solution {
public:
    int checkPalidrone(string s)
    {

        return  1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string maxPal = "";
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
                {
                    string str1 = s.substr(i, j+1-i);
                    string str2 = str1;
                    reverse(str2.begin(), str2.end());
                    if(str1 == str2)
                        {
                            if(str1.size() > maxPal.size())
                                maxPal = str1;
                        }
                }
        }
        return maxPal;
    }
};

*/


// Optimal solution got 80% beats
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0;
        int startInd = 0;
        string ans ="";
        for(int i=0; i<n; i++)
        {
            int left = i, right = i;
            while(left >=0 && right < n && s[left] == s[right])
            {
                if(maxLength < (right-left+1))
                    {   
                        startInd = left;
                        maxLength = (right-left+1);
                    }
                left--; right++;
            }
            
            left = i; right = i+1;
                while(left >=0 && right < n && s[left] == s[right])
                {
                    if(maxLength < (right-left+1))
                        {   
                            startInd = left;
                            maxLength = (right-left+1);
                        }
                    left--; right++;
                }
            
        }
        ans  = s.substr(startInd, maxLength);
    return ans;
    }
};
/*

*/