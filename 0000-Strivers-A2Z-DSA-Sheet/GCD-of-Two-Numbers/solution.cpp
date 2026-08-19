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

// without standard min function
// best recyrsuve way
int GCD(int a, int b) 
{
if(b==0) return a;
 return GCD(b, a%b);
}
// or Iterative
int GCD(int a, int b)
{
while(true) 
    {
      if(b===0) return a;
      int temp = a;
      a=b;
      b = temp%b;
    }
}
