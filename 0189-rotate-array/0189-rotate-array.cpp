class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k==0) return;
        vector<int> temp;
        for(int i=n-k; i<n; i++)
        {
           temp.push_back(nums[i]);
        }
            for(int i=0; i<n-k; i++)
        {
           temp.push_back(nums[i]);
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
//         int m=nums.size();
//         if(k%m==0) return;
//         int nk = (k)%(m);
//         vector<int> vt;
//         for(int i=0; i<m; i++)
//         {
//             vt.push_back(nums[(m-nk+i)%m]);
//         }
//         for(int i=0; i<m; i++)
//             nums[i] = vt[i];
//     return;
//     }
// };

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) 
//     {
//         int m=nums.size();
//         if(k%m==0) return;
//         int nk = (k)%(m);
//         vector<int> vt;
//         for(int i=0; i<m; i++)
//         {
//             vt.push_back(nums[(nk+i)%m]);
//         }
//         for(int i=0; i<m; i++)
//             nums[i] = vt[i];
//     return;
//     }
// };