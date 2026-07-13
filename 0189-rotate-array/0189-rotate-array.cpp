class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k==0) return;
        vector<int> temp;
        for(int i=0; i<n; i++)
        {
           temp.push_back(nums[(n-k+i)%n]);
        }
        for(int i=0; i<n; i++)
        {
            nums[i]=temp[i];
        }
    }
};












// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) 
//     {
//         int n=nums.size();
//         k = k%n;
//         if(k==0) return;
//         vector<int> vt;
//         for(int i=0; i<n; i++)
//         {
//             vt.push_back(nums[(k+i)%n]);
//         }
//         for(int i=0; i<n; i++)
//             nums[i] = vt[i];
//     return;
//     }
// };