// Time:  O(n^2)
// Space: O(1)
// brute force

class Solution {
public:
    string minimizeResult(string expression) {
        const auto& stoi = [](const auto& s, int i, int j) {
            if (i == j) {
                return 1;
            }
            int result = 0;
            for (int k = i; k < j; ++k) {
                result = result * 10 + (s[k] - '0');
            }
            return result;
        };
        const auto& pos = expression.find('+');
        int left = stoi(expression, 0, pos), right = stoi(expression, pos + 1, size(expression));
        int min_val = numeric_limits<int>::max();
        pair<int, int> best;
        const int base2_init = pow(10, size(expression) - (pos + 1) - 1);
        for (int i = 0, base1 = pow(10, pos); i < pos; ++i, base1 /= 10) {
            for (int j = pos + 1, base2 = base2_init; j < size(expression); ++j, base2 /= 10) {
                const int a = left / base1, b = left % base1;
                const int c = right / base2, d = right % base2;
                const auto& val = max(a, 1) * (b + c) * max(d, 1);
                if (val < min_val) {
                    min_val = val;
                    best = {i, j};
                }
            }
        }
        string result;
        for (int i = 0; i < size(expression); ++i) {
            if (i == best.first) {
                result.push_back('(');
            }
            result.push_back(expression[i]);
            if (i == best.second) {
                result.push_back(')');
            }
        }
        return result;
    }
};
