//same leetcode problem : 17. Letter Combinations of a Phone Number

//got 100% betas 
class Solution {
public:
    void solve(string &digits, vector<string> &ans, string &mp, vector<string> &pad, int i)
    {
        if(i==digits.size())
        {
            ans.push_back(mp);
            return;
        }
        for(int j=0; j<pad[digits[i]-'0'].size(); j++)
        {
            mp.push_back(pad[digits[i]-'0'][j]);
            solve(digits, ans, mp, pad, i+1);
            mp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string mp;
        solve(digits, ans, mp, pad, 0);
        return ans;

    }
}; 

//revision notes
/*
1. The Core Setup
Instead of picking/not-picking numbers, you are mapping digits to letters and looping through the options.

Depth (i): Tracks the current digit you are looking at in the input string.

Width (j loop): Loops through the letters available for that specific digit.

2. The Math Trick
pad[digits[i] - '0']
Subtracting '0' from a char converts it into an actual integer. This turns the character '2' into the number 2, allowing you to instantly fetch "abc" from your pad array at index 2.

3. The "Magic" Cycle (Winding and Unwinding)
This is the mechanism that amazed you. It builds every combination one by one:

Push: Pick the first letter (e.g., 'a').

Recurse: Call solve(i + 1) to freeze 'a' in place and move to the next digit.

Pop (Unwind): When the recursion finishes and hits a return, you jump back, erase 'a' using pop_back(), and the loop moves to 'b'.

4. The Edge Case Trap
If the input is "" (empty string), digits.size() is 0. If you don't catch this in the main function with if(digits.empty()) return ans;, your base case will blindly trigger and return [""] instead of []

*/