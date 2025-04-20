// Time:  O(mx * log(mn * c^2)) = O(mx * (logc + log(mn))), c = cars, mx = max(ranks), mn = min(ranks)
// Space: O(mx)
// freq table, binary search

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int, int> cnt;
        for (const auto& r : ranks) {
            ++cnt[r];
        }
        const auto& check = [&](int64_t x) {
            return accumulate(cbegin(cnt), cend(cnt), 0LL, [&](const auto& total, const auto& v) {
                return total + static_cast<int64_t>(sqrt(x / v.first)) * v.second;
            }) >= cars;
        };

        const int64_t mn = min_element(cbegin(cnt), cend(cnt), [](const auto& a, const auto& b) {
            return a.first < b.first;
        })->first;
        int64_t left = 1, right = mn * cars * cars;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
