
// my brute force solution TC is N power 2 as sum of N nums steps takes 72/144 passed
// time limit exceed as reverse and substr takes N each insdie so N3 Tc
/*
class Solution {
public:
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


// Optimal solution getting < 80% beats
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
            // by skipping the duplicates we can get 100% beats by using below  while loop and making i = right and no need the second while loop to check i+1
            while(right<n && s[right] == s[right+1])
                right++;
            i = right;

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

// logic explanation above problem as every single char in  a string as possilbe of palindrome
/*
Imagine the string is "racecar".
Instead of looking at the whole word, point your finger at the letter 'e' in the middle.

Move your left finger one step left (to 'c') and your right finger one step right (to 'c'). They match!

Move them outwards again: 'a' and 'a'. Match!

Move again: 'r' and 'r'. Match!

You just found the palindrome by starting in the middle and walking outwards. This is much faster than checking every possible substring.

In your for loop, you will treat every single letter as a center, and try to expand outwards.

Here is exactly how the pointers work for s = "babad":

1. The Odd-Length Center (like "bab")

You are at index 1 (the letter 'a').

You set left = 1 and right = 1.

You step outwards: left becomes 0 ('b'), right becomes 2 ('b').

They match! You found "bab".

2. The Even-Length Center (like "bb" in "cbbd")

Sometimes the center isn't a single letter. It's the space between two letters.

You are at index 1 (the first 'b').

You set left = 1 and right = 2 (the second 'b').

They match! You found "bb".

Inside your for (int i = 0; i < n; i++) loop, you just need two small while loops:

While Loop 1: Starts with left = i, right = i (expands while s[left] == s[right]).

While Loop 2: Starts with left = i, right = i + 1 (expands while s[left] == s[right]).

============================================
(with the duplicate skip):
=============================================
You are at index 1. left=1, right=1.

Your duplicate skip kicks in: "Wait, the next letter is also 'b'. Let me grab it."

It pushes right to 2.

Now, before the outward expansion even starts, your center is already left=1, right=2.

The duplicate skip automatically built the even-length center for you.
*/