// Time:  O(n)
// Space: O(1)
// prefix sum, greedy

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int result = 0;
        for (int i = size(nums) - 1, mx = 0; i >= 1; --i) {
            mx = max(mx, nums[i]);
            result += mx;
        }
        return result;
    }
};
