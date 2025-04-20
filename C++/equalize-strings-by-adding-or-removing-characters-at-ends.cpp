// Time:  O((n + m) * log(min(n, m)))
// Space: O(min(n, m))
// binary search, rolling hash

class Solution {
public:
    int minOperations(string initial, string target) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        const auto& rolling_hash = [](const auto& s, int l, auto& lookup, bool check) {
            static const int MOD = 1e9 + 7, P = 113;
    
            int64_t h = 0, pw = 1;
            for (int i = 0; i < size(s); ++i) {
                h = (h * P + (s[i] - 'a')) % MOD;
                if (i < l - 1) {
                    pw = (pw * P) % MOD;
                    continue;
                }
                if (!check) {
                    lookup.emplace(h);
                } else if (lookup.count(h)) {
                    return true;
                }
                h = ((h - (s[i - (l - 1)] - 'a') * pw % MOD) + MOD) % MOD;
            }
            return false;
        };

        const auto& check = [&](int l) {
            unordered_set<int> lookup;
            rolling_hash(target, l, lookup, false);
            return rolling_hash(initial, l, lookup, true);
        };

        if (size(initial) < size(target)) {
            swap(initial, target);
        }
        return size(initial) + size(target) - 2 * binary_search_right(1, min(size(initial), size(target)), check);
    }
};
