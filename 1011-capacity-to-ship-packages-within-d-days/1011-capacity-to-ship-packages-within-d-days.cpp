class Solution {
public:
    int calDays(vector<int>& weights, int w)
    {
        int days=1;
        int Wsum=0;
        for(int x : weights)
        {
            if(Wsum + x > w)
                {
                    days++;
                    Wsum=x;
                }
            else 
                Wsum += x;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = 1, right = 0;
        for(int w : weights)
        {
            left = max(left, w);
            right +=w;
        }
        int ans = right;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int reqDays = calDays(weights, mid);
            if(reqDays <= days)
                {
                    ans = mid;
                    right = mid-1;
                }
            else
                left = mid+1;
        }
        return ans;
    }
};