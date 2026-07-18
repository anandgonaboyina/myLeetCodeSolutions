
//similar follow up problem in leet code : 315. Count of Smaller Numbers After Self
//my brute force solution passed 63/66 but still it can encounter the N^2 TLE
// when array is completely has distinct numbers
/*
class Solution {
public:
    int numberOfInversions(vector<int>& nums) 
    {
        int n  = nums.size();
        if(n<2) return {0};
        vector<int> ans;
        int p=0;
        while(p<n)
        {
            int left = p+1, right=n-1;
            int cnt=0;
            while(left<=right)
            {
                if(nums[p]>nums[left])
                    cnt++;
                if(nums[p]>nums[right] && left !=right)
                    cnt++;
                left++; right--;
            }
            ans.push_back(cnt);
            p++;
            while(p<n && nums[p] == nums[p-1])
               {
                ans.push_back(cnt);
                p++;
               }
        }
        int sum=0;
        for(int x : ans)
            sum += x;
        return sum;
    }
};

*/

// optimal solution using merge sort algorithem logic
class Solution {
public:

    void mergeSort(vector<pair<int, int>> &numsInd, int left, int right, vector<int>&ans)
    {
        if(left>=right) return;
        int m = (left+right)/2;
        mergeSort(numsInd, left, m, ans);
        mergeSort(numsInd, m+1, right, ans);
        merge(numsInd, left, m, right, ans);
    }

    void merge(vector<pair<int, int>> &numsInd, int left, int m, int right, vector<int>&ans)
    {
        int i=left, j=m+1;
        int rightCnt=0;
        vector<pair<int,int>> temp;
        while(i<=m && j<=right)
        {
            if(numsInd[i].first <= numsInd[j].first)
            {
                temp.push_back(numsInd[i]);
                ans[numsInd[i].second] += rightCnt;
                i++;
            }
            else
            {
                temp.push_back(numsInd[j]);
                rightCnt++;
                j++;
            }
        }
        while(i<=m)
        {
            temp.push_back(numsInd[i]);
            ans[numsInd[i].second] +=rightCnt;
            i++;
        }
        while(j<=right)
        {
            temp.push_back(numsInd[j]);
            j++;
        }
        for(int i=left; i<=right; i++)
            numsInd[i]=temp[i-left];
    }

    int numberOfInversions(vector<int>& nums) 
    {
        int n  = nums.size();
        if(n<2) return {0};
        vector<int> ans(n, 0);
        vector<pair<int, int>>numsInd(n);
        for(int i=0; i<n; i++)
            numsInd[i]={nums[i],i};

        mergeSort(numsInd, 0, n-1, ans);
        int sum=0;
        for(int x : ans)
            sum += x;
        return sum;
    }
};