class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
    int n = nums.size();
        int left=0,mid=0, right=n-1;
            while(mid<=right)
        {
            if(nums[mid]==1)
                mid++;
            else if(nums[mid]==0)
                {
                    if(nums[left] !=0)
                        swap(nums[left], nums[mid]);
                    left++; mid++;
                }
            else if(nums[mid]==2)
                {
                    swap(nums[mid], nums[right]);
                    right--;
                }
        }
    }
};

//Brute force solution
/*
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
    vector<int> vt(3, 0);
    for(int x : nums)
    {
        vt[x]++;
    }
    for(int i=0; i<nums.size(); i++)
    {
        if(i<vt[0] )
            nums[i]=0;
        else if(i < vt[0] + vt[1])
            nums[i]=1;
        else
            nums[i]=2;
    }
    }
};
*/

//anandk



