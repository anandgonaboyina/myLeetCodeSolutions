class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();
        bool flag =true;
        for(int i=n-1; i>0; i--)
        {
            flag =true;
            for(int j=1; j<=i; j++)
            {
                if(nums[j-1]>nums[j])
                    {
                        flag =false;
                        swap(nums[j-1], nums[j]);
                    }

            } 
            if(flag) return nums;
        }
        return nums;
    }
};
