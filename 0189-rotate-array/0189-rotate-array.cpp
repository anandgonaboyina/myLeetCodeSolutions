// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k%n;
//         if(k==0) return;
//         vector<int> temp;
//         for(int i=0; i<n; i++)
//         {
//            temp.push_back(nums[(n-k+i)%n]);
//         }
//         for(int i=0; i<n; i++)
//         {
//             nums[i]=temp[i];
//         }
//     }
// };
////////////////////////////////////////////////////////////////////////////

// for extra space 1
// Reverse the entire array completely.
// Reverse the first k elements of that flipped array.
// Reverse the remaining n - k elements.

///manual reversing the array

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k)
//      {
//         int n = nums.size();
//         k = k%n;
//         if(k==0) return;
//         for(int i=0; i<n/2; i++)
//         {
//                 swap(nums[i], nums[n-1-i]);
//         }
//         int left1=0, right1=k-1;
//         while(left1<right1)
//         {
//                 swap(nums[left1], nums[right1]);
//                 left1++; right1--;
//         }
//         int left2=k, right2=n-1;
//         while(left2<right2)
//         {
//         swap(nums[left2], nums[right2]);
//             left2++; right2--;
//         }
//     }
//     };

/////////////////////////////////////////////////////////////////////////////////


//using the standard cpp library

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k==0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};


////////////////////first method another formula to get backside equvalent/////////////////////
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