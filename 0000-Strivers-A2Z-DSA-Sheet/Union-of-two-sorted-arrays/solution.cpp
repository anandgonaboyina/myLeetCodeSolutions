// class Solution {
// public:
//     vector<int> unionArray(vector<int>& nums1, vector<int>& nums2)
//     {
//         set<int> st;  
//         // it is ordered set for each insertion takes O(logn) time and
//         // total TC is for n=n1+n2 O(nlogn)
//         for(int x : nums1)
//         st.insert(x);
//         for(int x : nums2)
//         st.insert(x);
//         /*
//         vector<int> temp;
//                 for(auto it : st)
//         {
//             temp.push_back(it);
//         }
//         return temp; 
//         */
//         //or
//         return vector<int>(st.begin(), st.end());
//     }
// };

// if order not important we can use unordered_set as it takes insertion time O(1) as it uses hash table
// just initialize above one as below
//  unordered_set<int> st;

//Optimal approach

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.empty()) return nums2;
        if(nums2.empty()) return nums1;
        int left=0, right=0;
        int n1=nums1.size(), n2=nums2.size();

        vector<int> ans;
        while(left<n1 && right<n2)
        {
            if(nums1[left]==nums2[right])
                {
                    if(ans.empty() || ans.back() != nums1[left])
                        ans.push_back(nums1[left]);
                    left++; right++;
                }
            else if(nums1[left]<nums2[right])
                {
                    if(ans.empty() || ans.back() != nums1[left])
                        ans.push_back(nums1[left]);
                    left++;
                }
            else
                {
                    if(ans.empty() || ans.back() != nums2[right])
                        ans.push_back(nums2[right]);
                    right++;
                }
        }

        while(left<n1)
        {
            if(ans.back() != nums1[left])
                ans.push_back(nums1[left]);
            left++;
        }
        while(right<n2)
        {
            if(ans.back() != nums2[right])
                ans.push_back(nums2[right]);
            right++;
        }

        return ans;
    }
};
//kumar