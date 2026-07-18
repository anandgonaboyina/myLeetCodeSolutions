//my solution
class Solution {
public:
    int findPivot(vector<int>&nums)
    {
        int n = nums.size();
        int left =0, right=n-1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right =mid;
        }
        return left;
    }

    int findInd(vector<int>&nums, int left, int right, int target)
    {
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(target==nums[mid])
                return mid;
            else if (target < nums[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int pInd = findPivot(nums);
        if(target>nums[n-1])
            return findInd(nums, 0, pInd-1, target);
        return findInd(nums, pInd, n-1, target);
    }
};


///////////////////////////////////////////////////////////////////
//previous long ago solve solution dont even know when did i do
// as i used to be consistant less than 2 days at that time
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> vt;
        int k=0;
            while(k<n-1 && nums[k]<nums[k+1])
                k++;
            for(int i=0; i<n; i++)
                vt.push_back(nums[(n-k+i)%n]);
            int i=0, j=n-1;
            while(i<=j)
            {
                int m = i + (j-i)/2;
                if(target == vt[m])
                    return m-k>=0? m-k:m+k+1;
                else if(target < vt[m])
                    j=m-1;
                else if(target> vt[m])
                    i=m+1;
            }
        return -1;
    }
};
*/