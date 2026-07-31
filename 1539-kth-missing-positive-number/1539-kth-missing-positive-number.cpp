//  brute force solution beats 100% but not logN tc
/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int kth = k;
        for(int x : arr)
        {
            if(x<=kth)
                kth++;
            else
                break;
        }
        return kth;
    }
};
*/
// optimal binary solution so tc is logN
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int left=0, right=arr.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int missingNums = arr[mid]-(mid+1);
            if(missingNums < k)
                left= mid+1;
            else
                right = mid-1;
        }
        return left+k;
    }
};
