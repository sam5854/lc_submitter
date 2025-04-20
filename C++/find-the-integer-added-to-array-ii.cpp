// Time:  O(n)
// Space: O(n)
// partial sort, freq table

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        const auto& check = [](auto& cnt2, auto& cnt1) {
            unordered_set<int> keys;
            for (const auto& [k, _] : cnt2) {
                keys.emplace(k);
            }
            for (const auto& [k, _] : cnt1) {
                keys.emplace(k);
            }
            for (const auto& k : keys) {
                if (cnt2[k] > cnt1[k]) {
                    return false;
                }
            }
            return true;
        };

        partial_sort(begin(nums1), begin(nums1) + 3, end(nums1), greater<int>());
        unordered_map<int, int> cnt2;
        for (const auto& x : nums2) {
            ++cnt2[x];
        }
        const int mx = ranges::max(nums2);
        for (int i = 0; i < 3; ++i) {
            const int d = mx - nums1[i];
            unordered_map<int, int> cnt1;
            for (const auto& x : nums1) {
                ++cnt1[x + d];
            }
            if (check(cnt2, cnt1)) {
                return d;
            }
        }
        return -1;
    }
};
