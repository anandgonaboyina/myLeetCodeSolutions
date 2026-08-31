//optimal approach
/*
class Solution {
public:
    bool checkIthBit(int n, int i) {
       
        return  (n>>i & 1)==1;  //or bit mask way (1<<i) & n == 1;
    }
};
*/
//brute force
class Solution {
public:
    bool checkIthBit(int n, int i) {
       string binary = "";
       while(n>0)
       {
            binary += n%2 == 0 ? '0':'1';
            n = n/2;
       }
       if(i >= binary.size())
            return false;
        return  binary[i]=='1';
    }
};