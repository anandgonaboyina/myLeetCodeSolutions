//leetcode problem : 1903. Largest Odd Number in String
class Solution{	
public:		
    string largeOddNum(string& s)
    {
        string ans = "";
       for(int i=s.size()-1; i>=0; i--)
        {
            if((s[i]-0)%2 !=0)
                {
                    ans = s.substr(0, i+1);
                    break;
                }
        }
        for(int i=0; i<ans.length(); i++)
        {
            if((ans[i]-0) !=0)
                return ans.substr(0, ans.length());
        }
        return "";
    }
};