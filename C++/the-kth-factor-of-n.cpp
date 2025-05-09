// Time:  O(sqrt(n))
// Space: O(1)

class Solution {
public:
    int kthFactor(int n, int k) {
        const auto& [mid, count] = kthFactor_(n);
        int total = 2 * count - (mid * mid == n);
        if (k > total) {
            return -1;
        }
        int result = kthFactor_(n, (k <= count) ? k : total - (k - 1)).first;
        return (k <= count) ? result : n / result;
    }

private:
    pair<int, int> kthFactor_(int n, int k = 0) {
        int mid = -1;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i) {
                continue;
            }
            mid = i;
            if (!--k) {
                break;
            }
        }
        return {mid, -k};
    }
};
