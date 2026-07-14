// my brute force solution
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int, int>mp;
        for(int x : nums)
        {
            mp[x]++;
            if(mp[x]>n/2)
                return x;
        }
        return -1;
    }
};
*/
//for SC 1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0, candidate;
        for(int x : nums)
        {
            if(cnt==0)
                candidate=x;
            if(candidate==x)
                cnt++;
            else
                cnt--;
        }
        return candidate;
    }
};