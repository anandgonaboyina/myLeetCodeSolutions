// this is the minimize the maximum modal problem
// so same code logic works here too
// note here :
/*
we have to use long long instead int you can get to know once look at constrain limits of problem

In Book Allocation, if students > books (n < A), we returned -1 because every student must get a book.
In Painter's Partition, if we have 10 painters and 2 boards, 2 painters work and 8 go home. It is not impossible. The time taken is simply the time to paint the largest single board.
so no need if(n < A) return -1; check. The binary search will naturally handle it.
*/

// optimal binary solution using the logic of minimize the maximum
class Solution {
public:
    bool checkPainters(int A, int B, vector<int>& C, long long maxTime)
    {
        int cnt=1;
        long long currentTime =0;
        for(int x : C)
        {
            if(currentTime + x*B > maxTime)
            {
                cnt++;
                currentTime = x*B;
            }
            else
                currentTime += x*B;
        }
        return cnt <= A;
    }
    int paint(int A, int B, vector<int>& C) 
    {
        int n = C.size();
        long long left=0, right=0;   
        //check constrain limits as C[i]*B it goes beyond int limits 
        for(int x : C)
        {
            left = max(left, x);
            right += x;
        }
        right *= B;
        left *= B;
        long long ans = -1;
        if(n==A) return left % 10000003;
        while(left <= right)
        {
            long long mid = left + (right-left)/2;
            if(checkPainters(A, B, C, mid))
            {
                ans = mid;
                right = mid-1;
            }
            else
                left = mid + 1;
        }
        return ans % 10000003;
    }
};