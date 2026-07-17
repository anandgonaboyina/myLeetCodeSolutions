//my brute force solution ( optimal ) for tc as N but sc is N
/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
       int n =nums.size();
       unordered_map<int, int> mp;
       vector<int> ans;
       for(int i=0; i<n; i++)
       {
        mp[nums[i]]++;
        if(mp[nums[i]]>n/3)
           {
             ans.push_back(nums[i]);
             mp[nums[i]]=INT_MIN;
           }
       }
       return ans;
    }
};
*/
// optimal solution
//by using Boyer-Moore Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
       int n =nums.size();
       int m1, m1Cnt=0;
       int m2, m2Cnt=0;
       vector<int> ans;
       for(int i=0; i<n; i++)
       {
        if(m1==nums[i])
            m1Cnt++;
        else if(m2 == nums[i])
            m2Cnt++;
        else if(m1Cnt==0)
           {
                m1=nums[i];
                m1Cnt=1;
           }
        else if(m2Cnt==0)
            {
                m2=nums[i];
                m2Cnt=1;
            }
        else
            {
                m1Cnt--;
                m2Cnt--;
            }
       }
        int cnt1=0, cnt2=0;
        for(int x : nums)
        {
            if(x == m1)
                {
                    cnt1++;
                    if(cnt1>n/3)
                        {
                        cnt1=INT_MIN;
                        ans.push_back(m1);
                        }
                }
           else if(x==m2)  //else if m1=m2 to avoid duplicates
                {
                    cnt2++;
                    if(cnt2>n/3)
                        {
                            cnt2 =INT_MIN;
                            ans.push_back(m2);
                        }
                }
        }
        return ans;

    }
};