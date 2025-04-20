// Time:  O(n)
// Space: O(logn)
// codeforces, https://codeforces.com/problemset/problem/1303/D
// counting sort, greedy

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        const auto& floor_log2_x = [](int x) {
            return 8 * sizeof(int) - __builtin_clz(x) - 1;
        };

        int64_t total = accumulate(begin(nums), end(nums), 0ll);
        if (total < target) {
            return -1;
        }
        vector<int> cnt(floor_log2_x(*max_element(cbegin(nums), cend(nums))) + 1);
        for (const auto& x : nums) {
            ++cnt[floor_log2_x(x)];
        }
        int result = 0;
        for (int i = size(cnt) - 1; i >= 0; --i) {
            const int x = 1 << i;
            for (int _ = 0; _ < cnt[i]; ++_) { 
                if (x <= target) {
                    target -= x;
                    total -= x;
                } else if (total - x >= target) {
                    total -= x;
                } else {
                    cnt[i - 1] += 2;
                    ++result;
                }
            }
        }
        return result;
    }
};
