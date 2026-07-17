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
        unordered_map<int, int>mp;
        int cnt=0;
        int sum=0;
        mp[0]=1;
        for(int x : nums)
        {   sum +=x;
            if(mp.find(sum-k) != mp.end())
                {
                    cnt += mp[sum-k];
                }
            mp[sum]++;
        }
        return cnt;
    }
};