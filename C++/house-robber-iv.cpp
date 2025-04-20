// Time:  O(nlogn)
// Space: O(n)
// binary search, greedy

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        const auto& check = [&](const auto& x) {
            int cnt = 0;
            for (int i = 0; i < size(nums); ++i) {
                if (nums[i] <= x) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= k;
        };
        unordered_set<int> nums_set(cbegin(nums), cend(nums));
        vector<int> sorted_nums(cbegin(nums_set), cend(nums_set));
        sort(begin(sorted_nums), end(sorted_nums));
        int left = 0, right = size(sorted_nums) - 1;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(sorted_nums[mid])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return sorted_nums[left];
    }
};
