//my optimal brute force solution but modifies the input so look at another solution implementation of same approach
/*
class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) 
    {
        int n= arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n; i++)
        {
        if(i<n-1 && arr[i][1]>=arr[i+1][0])
        {
            arr[i+1][0]=arr[i][0];
            if(arr[i][1]>arr[i+1][1])
            {
                arr[i+1][1]=arr[i][1];
            }
        }
        else
        ans.push_back(arr[i]);
        }
        return ans;
    }
};
*/
// ***same solution without modify the given arr
//and in less lines

//here no modifing the input array
class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) 
    {
        int n= arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0])
        for(int i=1;i<n; i++)
        {
            if(ans.back()[1]>=arr[i][0])
                ans.back()[1]=max(ans.back()[1], arr[i][1])
            else
                ans.push_back(arr[i]);
        }
        return ans;
    }
};
