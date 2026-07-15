///brute force approach but it can get TLE error when array size is 10^5 even without 2D vector okay
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int maxLen=0; 
        int n= nums.size();
        for(int i=0; i<n; i++)
        {
            int currentSum=0;
            for(int j=i; j<n; j++)
        {
/*      vt.push_back(vector<int>(nums.begin()+i, nums.begin()+1+j)); 
        if we use as it is 2D Array it consume GBs of memory
         if size of array is around 10^5 
*/
            currentSum +=nums[j];
                if(currentSum==k)
                {
                    if(maxLen<j-i+1)
                        maxLen=j-i+1;
                    // OR maxLen = max(maxLen, j-i+1); 
                }
        }
        }
        return maxLen;
    }
};

//Better solution using Hash Map

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int len=0; 
        int n= nums.size();
        unordered_map<int, int> mp;
        int prefixSum=0;
        for(int i=0; i<n; i++)
        {
            prefixSum +=nums[i];
            if(prefixSum==k)
                len=i+1;
            if(mp.find(prefixSum-k) != mp.end())
                len=i-mp[prefixSum-k];
                // since we remove the remaining part including the index of that prefixSum
            if(mp.find(prefixSum) == mp.end())
                mp[prefixSum] = i;
        }
        return len;
    }
};

//Optimal solution using the two pointer
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int maxLen=0; 
        int n= nums.size();
        int j=0, sum=0;
        for(int i=0; i<n; i++)
        {
                sum +=nums[i];
                while(sum>k && j<=i)
                {
                    sum =sum-nums[j];
                    j++;
                }
            if(sum==k)
                maxLen = max(maxLen, i-j+1);
        }
        return maxLen;
    }
};
//anand
