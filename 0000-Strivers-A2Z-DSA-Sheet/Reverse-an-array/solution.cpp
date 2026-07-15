class Solution{
public:
    void reverse(int arr[], int n){
        //recursively
        // if(n<=1) return;
        // swap(arr[0], arr[n-1]);
        // reverse(arr+1, n-2);
            //or 
        int l=0, r=n-1;
        while(l<r)
        {
            swap(arr[l], arr[r]);
            l++; r--;
        }
    }
};
