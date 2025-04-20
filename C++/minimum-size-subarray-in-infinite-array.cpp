// Time:  O(n)
// Space: O(1)
// two pointers, sliding window

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        static const int INF = numeric_limits<int>::max();

        const int64_t total = accumulate(cbegin(nums), cend(nums), 0ll);
        const int64_t q = target / total;
        target %= total;
        if (!target) {
            return q * size(nums);
        }
        int result = INF;
        int curr = 0;
        for (int right = 0, left = 0; right < (size(nums) - 1) + (size(nums) - 1); ++right) {
            curr += nums[right % size(nums)];
            while (curr > target) {
                curr -= nums[left++ % size(nums)];
            }
            if (curr == target) {
                result = min(result, right - left + 1);
            }
        }
        return result != INF ? result + q * size(nums) : -1;
    }
};
