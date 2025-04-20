// Time:  O(sqrt(n))
// Space: O(1)

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<vector<int>> results = {divisors(num + 1), divisors(num + 2)};
        return *min_element(cbegin(results), cend(results),
                            [](const auto& a, const auto& b) {
                                return a[1] - a[0] < b[1] - b[0];
                            });
    }

private:
    vector<int> divisors(int n) {
        for (int d = sqrt(n); d >= 1; --d) {
            if (n % d == 0) {
                return {d, n / d};
            }
        }
        return {1, n};
    }
};
