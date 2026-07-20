//
class Solution{
// brute force reverse string and check
// discarded function as it creates the copy of substring every time;
    string reverseString(string& s)
    {
        int l = s.length();
        if(l<1) return "";
        return s.back() + reverseString(s.substr(0, l-1));
    }

//clean Optimal two pointer approach
    bool checkPalidrone(string &s, int left, int right)
    {
        if(left>=right) return true;
        return ( s[left]==s[right] ) && checkPalidrone(s, left+1, right-1);
    }
	public:
		bool palindromeCheck(string& s)
        {
			//method 1
            // string temp =s;
            // return reverseString(temp, temp.length())==s;

            //recurstion way
            return checkPalidrone(s, 0, s.length()-1);
		}
};

