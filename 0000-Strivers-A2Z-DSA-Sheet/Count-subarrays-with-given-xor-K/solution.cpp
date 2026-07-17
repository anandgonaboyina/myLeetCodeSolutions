//my brute force solution is my optimal solution
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt=0, currentXOR=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0; i<n; i++)
        {
            currentXOR ^=nums[i];
            if(mp.find(currentXOR^k) != mp.end())
            {
                cnt=cnt+mp[currentXOR^k];
            }
            mp[currentXOR]++;
        }
        return cnt;
    }
};