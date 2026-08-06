//my brute force solution adopted from the logic of array rotate

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