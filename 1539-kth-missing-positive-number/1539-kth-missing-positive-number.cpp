//  brute force solution
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

/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        
    }
};
*/