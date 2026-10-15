//optimized 100% beats as TC is log5N
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt =0;
        int num =n;
        while(num >0)
        {
            cnt += num /5;
            num /= 5;
        }
        return cnt;
    }
};
// Time Complexity: O(log5(N))
// Space Complexity: O(1)
/*
REVISION NOTES: LEGENDRE'S FORMULA (HOW THE MATH WORKS)

1. The "Hidden 5s" Problem (Example: 25!):
   - The multiples of 5 in 25! are: 5, 10, 15, 20, 25.
   - Most have one 5 (e.g., 15 = 5 * 3).
   - But 25 holds TWO 5s (25 = 5 * 5). 
   - Total 5s to count = 6.

2. The Division Layers (Sweeping the Net):
   - Layer 1 (N / 5): Asks "How many numbers have at least one 5?" 
     (25 / 5 = 5). We caught five 5s.
   - Layer 2 (N / 25): Asks "How many numbers have a SECOND 5?" 
     (25 / 25 = 1). We caught the extra 5 hiding inside 25.
   - Total = 5 + 1 = 6.

3. The Code Logic (n /= 5):
   - Instead of tracking powers of 5 (5, 25, 125), we just update 'n'.
   - Step 1: n = 25 -> count += 5. (n becomes 5)
   - Step 2: n = 5  -> count += 1. (n becomes 1). This acts as the /25 sweep!
   - Step 3: n = 1  -> Loop breaks.
*/



//my brute force solution getting 2-4% beats only due to checkinge every number
/*
class Solution {
public:
    int trailingZeroes(int n) {
        int num = n;
        int ans=0;
        pair<int, int> p={0,0};
        while(num !=0)
        {
            int x = num;
            while(x % 2 ==0)
            {
                p.first++;
                x /= 2;
            }
            while(x % 5 ==0)
            {
                p.second++;
                x /= 5;
            }
           num -= 1;
        }
        ans = min(p.first, p.second);
        return ans;
    }
};
*/