//my brute force solution adopted from the logic of array rotate
// got 100% beats

/*
class Solution {
public:
    bool rotateString(string s, string goal) {
        
        for(int i=0; i<s.size(); i++)
        {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            reverse(s2.begin(), s2.begin()+i+1);
            reverse(s2.begin()+i+1, s2.end());
            if(s2==goal)
                return true;
        }
        return false;
    }
};
*/
//optimal way to solve this problem
//better logic for less code

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        string doubleStr = s + s;
        if(doubleStr.find(goal) != -1)
            return true;
        return false;
    }
};