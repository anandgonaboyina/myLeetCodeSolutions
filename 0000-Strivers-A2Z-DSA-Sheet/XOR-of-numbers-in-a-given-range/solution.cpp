/* 
Approach 1: my brute force solution
TC is N ans SC is 1;
Note: This works for small numbers but will give Time Limit Exceeded (TLE) 
in competitive programming if the range is up to 10^9.
==> Time Complexity: O(N), where N is the number of elements between L and R.
Space Complexity: O(1)
*/
/*
class Solution{	
	public:
		int findRangeXOR(int l,int r){
			int ans =0;
            for(int i=l; i<=r; i++)
                ans ^=i;
            return ans;
		}
};
*/
/*
===========================================
 Approach 2: Optimal Math Approach
 ========================================
better way
since, XOR(L, R) =  XOR(1, L-1)  ^ XOR(1, R) = L ^ L+1 ^ ... ^ R
so Logic: XOR(L, R) = XOR(1, L-1) ^ XOR(1, R)
Why? Because XORing a number with itself cancels it out (X ^ X = 0).
XORing from 1 to R gives us everything, and XORing from 1 to L-1 
"erases" the numbers before L that we don't want.
Time Complexity: O(1) -> Instant math calculation.
Space Complexity: O(1)
*/
class Solution{	
	public:
        // Helper function: Finds XOR of all numbers from 1 to n in O(1) time
        // Based on the repeating pattern of 4 in binary XOR sums.
        int findXOR(int n)
        {
            int mod = n%4;
            if(mod == 0) return n;
            else if(mod == 1) return 1;
            else if(mod == 2) return n+1;
            else 
                return 0;
        }

		int findRangeXOR(int l,int r){
			return findXOR(l-1)^findXOR(r);
		}
};
