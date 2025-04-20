// Time:  O(b)
// Space: O(b)
// math

class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        int k = min(static_cast<int>(((-1 + sqrt(1 + 8 * maxSum)) / 2)), n); // k = argmax((k+1)*k//2 <= maxSum)
        int64_t total = static_cast<int64_t>(k + 1) * k / 2;
        int result = k;
        unordered_set<int> lookup(cbegin(banned), cend(banned));
        for (const auto& x : lookup) {
            if (x <= k) {
                total -= x;
                --result;
            }
        }
        for (int i = k + 1; i <= n; ++i) {
            if (lookup.count(i)) {
                continue;
            }
            if (total + i > maxSum) {
                break;
            }
            total += i;
            ++result;
        }
        return result;
    }
};
