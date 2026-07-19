//brute force linear search
/*
class Solution {
public:
  int NthRoot(int N, int M) 
    {
       for(int x=0; pow(x, N)<=M; x++)
            if(pow(x, N)==M)
                return x;
    }
    return -1;
};

*/
//optimal solution using binary search
// using the one more function to cut it down before reaching the exceed limit

class Solution {
public:

    int checkPower(int x, int n, int m)
    {
        long long ans=1; 
        for(int i=1; i<=n; i++)
        {
            ans *=x;
            if(ans>m)
                return 2;
        }
        if(ans==m)
            return 0;
        else
            return 1;
    }
  int NthRoot(int N, int M) 
    {
        int left=0, right=M;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int isMid = checkPower(mid, N , M);
            if(isMid  == 0) return mid;
            else if(isMid == 2)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }

};






//discarded optimal solution as pow casues truncate errors interanlly for integers
class Solution {
public:
  int NthRoot(int N, int M) 
    {
       for(int x=0; pow(x, N)<=M; x++)
            if(pow(x, N)==M)
                return x;
        int left=1, right=M;
        int ans;
        while(left<=right)
            {
               int mid = left + (right-left)/2;
               if(pow(mid, N)<M)
                    {
                        left= mid+1;
                    }
                else if(pow(mid, N)== M)
                    return mid;
                else
                    right = mid-1;
            }
    return -1;
    }
};

