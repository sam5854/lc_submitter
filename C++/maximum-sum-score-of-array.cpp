// Time:  O(n)
// Space: O(1)
// prefix sum, math

class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int64_t result = numeric_limits<int>::min();
        int64_t prefix = 0, suffix = 0;
        for (int left = 0, right = size(nums) - 1; left < size(nums); ++left, --right) {
            prefix += nums[left];
            suffix += nums[right];
            result = max({result, prefix, suffix});
        }
        return result;
    }
};
