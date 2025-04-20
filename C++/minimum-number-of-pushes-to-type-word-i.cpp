// Time:  O(4)
// Space: O(1)
// greedy

class Solution {
public:
    int minimumPushes(string word) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        int result = 0;
        const int l = ceil_divide(size(word), (9 - 2 + 1));
        for (int i = 0; i < l; ++i) {
            result += (i + 1) * min(static_cast<int>(size(word)) - i * (9 - 2 + 1), (9 - 2 + 1));
        }
        return result;
    }
};
