class Solution{	
	public:
		bool isSorted(vector<int>& nums){
			if(nums.size()<2) return true;
            for(int i=1; i<nums.size(); i++)
            {
                if(nums[i-1]>nums[i])
                    return false;
            }
            return true;
		}
};