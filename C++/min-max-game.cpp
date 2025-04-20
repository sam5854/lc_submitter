// Time:  O(n)
// Space: O(n)
// simulation, optimized from solution2

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for (int n = size(nums); n != 1; n /= 2) {
            for (int i = 0; i < n / 2; ++i) {
                nums[i] = (i % 2 == 0 ? min(nums[2 * i], nums[2 * i + 1]) : max(nums[2 * i], nums[2 * i + 1]));
            }
        }
        return nums[0];
    }
};
