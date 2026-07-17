//my brute force solution
/*
class Solution{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n=nums.size(), cnt=0;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum==k)
                    cnt++;
            }
        }
        return cnt;
    }
};

*/
//otpimal approach
class Solution{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n=nums.size(), cnt=0;
        unordered_map<int, int>mp;
        int sum=0;
        mp[0]=1;
        for(int i=0; i<n; i++)
        {   sum +=nums[i];
            if(mp.find(sum-k) != mp.end())
                {
                    cnt = cnt + mp[sum-k];
                }
            mp[sum]++;
        }
        return cnt;
    }
};