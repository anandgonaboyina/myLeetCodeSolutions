//my optimal brute force solution but modifies the input intervals
// so look at another solution implementation of same approach with less confusion without nested ifs
/*
/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n; i++)
        {
        if(i<n-1 && intervals[i][1]>=intervals[i+1][0])
        {
            intervals[i+1][0]=intervals[i][0];
            if(intervals[i][1]>intervals[i+1][1])
            {
                intervals[i+1][1]=intervals[i][1];
            }
        }
        else
        ans.push_back(intervals[i]);
        }
        return ans;
    }
};
*/
// ***same solution without modify the given intervals with less confusion
//and in less lines

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n; i++)
        {
            if(ans.back()[1]>=intervals[i][0])
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
