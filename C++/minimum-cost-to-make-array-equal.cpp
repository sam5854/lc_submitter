// Time:  O(nlogn)
// Space: O(n)
// math, binary search

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        const auto& f = [&](int x) {
            int64_t result = 0;
            for (int i = 0; i < size(nums); ++i) {
                result += static_cast<int64_t>(abs(nums[i] - x)) * cost[i];
            }
            return result;
        };

        const auto& check = [&](int x, int64_t t) {
            int64_t cnt = 0;
            for (int i = 0; i < size(nums); ++i) {
                if (nums[i] <= x) {
                    cnt += cost[i];
                }
            }
            return cnt >= t;
        };

        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return nums[a] < nums[b];
        });
        int left = 0, right = size(idxs) - 1;
        const int64_t total = accumulate(cbegin(cost), cend(cost), 0ll);
        const int64_t median = (total + 1) / 2;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (check(nums[idxs[mid]], median)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return f(nums[idxs[left]]);
    }
};
