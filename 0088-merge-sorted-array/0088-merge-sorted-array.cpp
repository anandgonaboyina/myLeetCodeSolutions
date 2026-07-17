//my brute force solution is the better solution tc is (m+n)log(m+n)
/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for(int i=0; i<n; i++)
        {
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
*/
//optimal solution tc as m+n
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if(n==0) return;
        if(m==0)
        {
            nums1 = nums2;
            return;
        }
        int r1=m-1, r2=n-1;
        int p=m+n-1;
        while(r1>=0 && r2 >=0)
        {
            if(nums1[r1]>=nums2[r2])
            {
                nums1[p]=nums1[r1];
                r1--;
            }
            else
            {
                nums1[p]=nums2[r2];
                r2--;
            }
            p--;
        }
        while(r2>=0)
        {
            nums1[p]=nums2[r2];
            r2--;
            p--;
        }
    }
};