
//my brute force solution
class Solution {
public:
    string reverseWords(string s) 
    {
        string ans = "";
        int right = s.length()-1;
        while(right >= 0)
        {
            while(right >= 0 && s[right] == ' ')
                right--;
            if(right <0)
                break;
            if(ans.length() !=0)
                ans += ' ';
            int left = right;
            while( left >0 && s[left-1] != ' ')
                left--;
            if(s[left] != ' ')
            for(int i=left; i<=right; i++)
                {
                    ans += s[i];
                }
            right = left -1;
        }
        return ans;
    }
};


/*
//by mistake i read as reverse string so this is for that my brute force solution
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int right=s.length()-1;
        while(right>0)
        {
            if(ans.back() == '' && ch== ' ' || ans.back() == ' ')
                continue;
            else
                ans += s[right];
            right--;
        }
        return ans;
    }
};


*/