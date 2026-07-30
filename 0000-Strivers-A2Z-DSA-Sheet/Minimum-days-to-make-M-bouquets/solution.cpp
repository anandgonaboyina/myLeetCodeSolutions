//leet code problem : 1482. Minimum Number of Days to Make m Bouquets
class Solution {
public:

    int calBouqets(vector<int>&bloomDay, int k, int days)
    {
        int cnt=0;
        int bouqets=0;
        for(int x : bloomDay)
        {
            if(days>=x)
             {   cnt++;
                 if(cnt == k)
                    {
                        bouqets++;
                        cnt=0;
                    }
             }
            else
                cnt=0;
        }
        return bouqets;
    }

int roseGarden(int n, vector<int> bloomDay, int k, int m)
    {
        if((long long)k*m > n) return -1;
        int left=1, right=0;
        for(int x : bloomDay)
            right = max(right, x);
        int ans = right;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int bouqets = calBouqets(bloomDay, k, mid);
            if(bouqets >= m)
                {
                    ans = mid;
                    right=mid-1;
                }
            else
                left = mid+1;
        }
        return ans;
    } 
};


