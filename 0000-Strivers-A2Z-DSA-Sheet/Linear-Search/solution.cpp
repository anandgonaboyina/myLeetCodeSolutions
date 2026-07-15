// class Solution {
// public:
//     int linearSearch(vector<int>& nums, int target) {
//         if(nums.empty()) return -1;
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i]==target)
//             return i;
//         }
//         return -1;
//     }
// };


///////////////// PRO TIP ////////////////////

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) 
    {
        if(nums.empty())
        return -1;
        auto it = find(nums.begin(), nums.end(), target);
        if(it !=nums.end())
        {
            return distance(nums.begin(), it);
        }
        return -1;
    }
};