//my brute force solution
/*
class Solution{   
public:    
    int minBitsFlip(int start, int goal) {
        int minflips =0;
       for(int i=0; i<=31; i++)
       {
            bool doflip = (start>>i & 1) != (goal>>i & 1);
            if(doflip)
            {
                // start = start ^ 1<<i; if asked to flip it
                minflips++;
            }
       }
        return minflips;
    }
};
*/
// best appraoch using Brian Kernighan's algorithm n & (n-1).
class Solution{   
public:    
    int minBitsFlip(int start, int goal) {
        int minflips =0;
        int diff = start ^ goal;  
        // this gives direct different bits in both to 1 so counting 1s is ans
        while(diff>0)
        {
            diff = (diff) & (diff-1);   // Deletes the lowest 1-bit
            minflips++;
        }
        return minflips;
    }
};

