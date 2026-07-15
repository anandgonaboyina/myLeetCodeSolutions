class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0) return;
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+n-k);
            reverse(nums.begin()+n-k, nums.end());
    }
};












//