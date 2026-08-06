// optimal solution
/*
class Solution {
public:
    string largestOddNumber(string num) {
        int right = 0;
        for(int i=num.length()-1; i>=0; i--)
        {
            if((num[i]-0) %2 != 0)
            {
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};
*/
//if leading zeros are there then 
class Solution{	
public:		
    string largestOddNumber(string& s)
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


/*
// foolish solution as just need to care about the last digit if it odd we can return the string upto there
//that too the length of the string is till 10^5 means greater 10 digits means out of int overflow
        int n = 0;
        for(char x : num)
        {
                n += (int)x - 48;
        }
        while(n% 2 == 0)
            n = n/10;
        string ans = "";
        if(n !=0)
            ans += n;
        return ans;

*/