//my optimal solution
class Solution {
  public:
    int maxLen(vector<int>& arr)
    {   int n =arr.size();
        unordered_map<int, int>mp;
        int maxL=0, sum=0;
        for(int i =0; i<n; i++)
        {
            sum += arr[i];
            if(sum==0)
                maxL = i+1;
            else if(mp.find(sum-0) !=mp.end())
                {
                    maxL = max(maxL, i-mp[sum]);
                }
        if(mp.find(sum) == mp.end())
            mp[sum]=i;
        }
        return maxL;
    }
};