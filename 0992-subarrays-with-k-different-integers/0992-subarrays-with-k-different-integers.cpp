//my brute force solution : timelimit exceed at 41/57 due to map used it makes to cross 10^9 TC
/*
class Solution {
public:
    int noKdifferentSubArrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        if(k>n) return 0;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            vector<int> hashArr(n+1, 0);
            int currentCnt =0;
            for(int j=i; j<n; j++)
            {
                if(hashArr[nums[j]] == 0)
                        {
                            currentCnt++;
                            hashArr[nums[j]] += 1;
                        }
                if(currentCnt == k)
                    cnt++;
                else if(currentCnt > k)
                    break;
            }
        }
    return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return noKdifferentSubArrays(nums, k);
    }
};
*/
//optimal solution

class Solution {
public:
    int atMost(vector<int> &nums, int k)
    {
        int n = nums.size();
        if(k>n) return 0;
        vector<int> hashArr(n+1, 0);
        int distinctCnt=0;
        int left =0, right=0;
        int totalSubStrings = 0;
        while(right<n)
        {
            if(hashArr[nums[right]] == 0)
            {
                distinctCnt++;
            }
            hashArr[nums[right]]++;
            while(distinctCnt > k)
                {   hashArr[nums[left]]--;
                    if(hashArr[nums[left]] == 0)
                        distinctCnt--;
                    left++;
                }
            totalSubStrings += (right - left) +1;  // right - left + 1 adds ALL valid subarrays ending at 'right'
            right++;
        }
        return totalSubStrings;
        }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1) ;
    }
};

















//understand this solution
/*
class Solution {
public:
    // Helper function to find subarrays with AT MOST k distinct integers
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(n + 1, 0); // Much faster than unordered_map
        int left = 0, right = 0;
        int distinctCnt = 0;
        int totalSubarrays = 0;
        
        while (right < n) {
            // If we are seeing this number for the first time
            if (freq[nums[right]] == 0) {
                distinctCnt++;
            }
            freq[nums[right]]++;
            
            // If we exceeded k distinct characters, shrink the window from the left
            while (distinctCnt > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    distinctCnt--;
                }
                left++;
            }
            
            // The number of valid subarrays ending at 'right' is exactly the size of the window
            totalSubarrays += (right - left + 1);
            right++;
        }
        
        return totalSubarrays;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // The mathematical sliding window trick
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
*/