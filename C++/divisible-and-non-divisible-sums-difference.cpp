// Time:  O(1)
// Space: O(1)
// math

class Solution {
public:
    int differenceOfSums(int n, int m) {
        const auto& arithmetic_progression_sum  = [](const auto& a, const auto& d, const auto& l) {
            return (a + (a + (l - 1) * d)) * l / 2;
        };

        return arithmetic_progression_sum(1, 1, n) - 2 * arithmetic_progression_sum(m, m, n / m);
    }
};
