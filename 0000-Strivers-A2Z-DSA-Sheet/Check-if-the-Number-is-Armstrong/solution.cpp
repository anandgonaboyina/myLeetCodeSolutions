class Solution {
public:
    bool isArmstrong(int n) {
        if(n==0) return true;
        int ndigits = (int)log10(n)+1;
        int num =n; long long ans=0;
        while(num>0)
       { 
        ans += round(pow(num%10, ndigits)); //round for avoiding truncate error with pow funciton
            // OR manual method below 
            // long long powerResult =1;
            // for(int i=0; i<ndigits; i++)
            // {
            //     powerResult *= num%10;
            // }
        num = num/10;
       }
       return n==ans;
    }
};