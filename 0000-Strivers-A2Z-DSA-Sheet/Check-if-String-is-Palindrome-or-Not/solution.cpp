class Solution{
    string reverseString(string& s, int n)
    {
        if(n<1) return "";
        return string(1, s[n-1])+reverseString(s, n-1);
    }
    bool checkP(string str, int s, int e)
    {
        if(s >= e) return true;
        return (str[s] == str[e]) && checkP(str, s+1, e-1);
    }
	public:		
		bool palindromeCheck(string& s)
        {
			//method 1
            // string temp =s;
            // return reverseString(temp, temp.length())==s;

            //recurstion way
            return checkP(s, 0, s.length()-1);
		}
};