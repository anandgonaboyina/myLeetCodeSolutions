//brute force solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n,0);
        int posInd=0, negInd=1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
            {
                ans[posInd]=nums[i];
                posInd +=2;
            }
            else
            {
                 ans[negInd] = nums[i];
                 negInd +=2;
            }
        }
        return ans;
    }
};


// better approach to make sc as 1
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) 
//     {
//         int first=0, second=1;
//         int n=nums.size();
//         int i=1;
//                     while(nums[0] <0 && i <n)
//                 {
//                     if(nums[i]>0)
//                     swap(nums[0], nums[i]);
//                     i++;
//                 }
//             i=0;
//         for(i; i<n; i++)
//         {
//             if(nums[i]>0)
//                 {
//                     swap(nums[first], nums[i]);
//                     first +=2;
//                 }
//             else
//                 {
//                     swap(nums[second], nums[i]);
//                     second +=2;
//                 }
//         }
//         return nums;
//     }
// };
