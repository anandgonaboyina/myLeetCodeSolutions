//brute force solution but problem is TLE for array of 10^5 size
/*
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size(), maxProfit=0, profit=0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                profit=prices[j]-prices[i];
                maxProfit= max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};
*/
//////////////////////////////////////
//better approach

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minp=prices[0], maxp=0;
        for(int i=0; i<prices.size(); i++)
       {
            minp = min(minp, prices[i]);
            maxp = max(maxp, prices[i]-minp);
       }
       return maxp;
    }
};
