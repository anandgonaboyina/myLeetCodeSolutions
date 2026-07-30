class Solution {
private:
    // Helper function to calculate total hours for a given speed
    long long calculateHours(vector<int>& piles, int speed) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += pile / speed;
            if (pile % speed != 0) {
                totalHours++; // Koko stays for the full hour even if she finishes early
            }
        }
        return totalHours;
    }

public:
    int minimumRateToEatBananas(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        // Finding max pile to set the upper bound
        for (int pile : piles) {
            right = max(right, pile);
        }
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long reqHours = calculateHours(piles, mid);
            
            if (reqHours <= h) {
                ans = mid;       // This speed is valid, remember it
                right = mid - 1; // Try finding a slower (smaller) valid speed
            } else {
                left = mid + 1;  // Too slow, she needs to eat faster
            }
        }
        
        return ans;
    }
};
