// premium leetcode problem : (medium level)
//my brute force solution
class Solution {
public:
    int findIntEqualant(char ch)
    {
       switch(ch)
       {
        case 'I':
            return 1; break;
        case 'V':
            return 5; break;
        case 'X':
            return 10; break;
        case 'L':
            return 50; break;
        case 'C':
            return 100; break;
        case 'D':
            return 500; break;
        case 'M':
            return 1000; break;
       }
       return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        int n1=0, n2=0;
        for(int i=0; i<s.size(); i++)
        {
            n1= findIntEqualant(s[i]);
            if(i < s.size()-1)
            {
                n2 = findIntEqualant(s[i+1]);
                if(n1 < n2)
                    {
                        ans += n2 - n1;
                        i++; // as i+1 also we taken so skippin the i
                        continue;
                    }
            }
            ans += n1;
        }
            return ans;
// Better way to write above logic in clean and short
        ///    SIMPLY WE CAN WRITE CODE AS WE JUST HAVE TO REMOVE THE SMALLER VALUE FROM BIGGER MEANS THOSE ARE AT I IF LESS THAN I+1 REMOVE FROM ANS AND THEN NEXT I+1 WILL GET ADD TO ANS
        /*

        int ans = "";
        for(int i=0; i<s.size(); i++)
            if(i<s.size()-1 && findIntEqualant(s[i]) < findIntEqualant(s[i+1]))
                ans -= findIntEqualant(s[i]);
            else
                ans += findIntEqualant(s[i]);
        return ans;

        */

    }
};



