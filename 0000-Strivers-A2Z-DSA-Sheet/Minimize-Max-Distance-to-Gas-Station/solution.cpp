//leet code problem same question but locked for free users
//HARD level Problem took 2hr to got it but still some clarity missing code is correct
//if not get while revising within 15min just go to learn solution how it works 
//otherwise your time is going to waste

class Solution {
public:
    int calNoStations(vector<int> &arr, long double dist)
    {
        int total = 0;
        for(int i=1; i<arr.size(); i++)
        {
            int gap = (arr[i]-arr[i-1]);
            int stations = ceil(gap/dist) -1 ;
            total += stations;
        }
        return total;
    }
    long double minimiseMaxDistance(vector<int> &arr, int k) 
    {
       int n = arr.size();
       long double left = 0, right=0;
       for(int i=1; i<n; i++)
       {
        right = (double)max(right, arr[i]-arr[i-1]);
       }
    while(right-left > 1e-10)
    {
        long double mid = left + (right-left)/2.0;
        if(calNoStations(arr, mid) <= k)
            right = mid;
        else
            left = mid;
    }
    return right;
    }
};