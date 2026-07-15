// class Solution {
// public:
//     int GCD(int n1,int n2) 
//     {
//         // int n = n1<n2? n1:n2;  // or min(n1, n2)
//         for(int i=min(n1, n2); i>0; i--)
//             {
//                 if(n1%i==0 && n2%i==0)
//                     return i;
//             }
//     }
// };


class Solution {
public:
    int GCD(int n1,int n2) 
    {
        while(true)
            {
                min(n1,n2)==n1?(n2=n2-n1):(n1=n1-n2);
                if(n1==0) return n2;
                if(n2==0) return n1;
            }
    }
};