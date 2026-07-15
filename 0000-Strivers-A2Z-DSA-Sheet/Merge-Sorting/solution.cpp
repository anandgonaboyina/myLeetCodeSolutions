class Solution {
public:
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if(left>=right) return;
        int mid = (left+right)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);

    }
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> temp;
        int l=left, r=mid+1;
        while(l<=mid && r<=right)
        {
            if(nums[l]<=nums[r])
                {
                    temp.push_back(nums[l]);
                    l++;
                }
            else
                {
                    temp.push_back(nums[r]);
                    r++;
                }
        }
        while(l<=mid)
        {
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=right)
        {
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=left; i<=right; i++)
        {
            nums[i]=temp[i-left];
        }

    }
    vector<int> mergeSort(vector<int>& nums) 
    {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
