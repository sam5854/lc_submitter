// Time:  O(n)
// Space: O(n)
// mono stack, prefix sum, optimized from solution2

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        static const int MOD = 1e9 + 7;
        const auto& add = [&](const int64_t a, const int64_t b) {
            return (a + b) % MOD;
        };
        const auto& sub = [&](const int64_t a, const int64_t b) {
            return (a - b + MOD) % MOD;
        };
        const auto& mult = [&](const int64_t a, const int64_t b) {
            return (a * b) % MOD;
        };
        vector<int64_t> prefix(size(strength) + 1);
        int64_t curr = 0;
        for (int i = 0; i < size(strength); ++i) {
            curr = add(curr, strength[i]);
            prefix[i + 1] = add(prefix[i], curr);
        }
        vector<int> stk = {-1};
        int result = 0;
        for (int i = 0; i <= size(strength); ++i) {
            while (stk.back() != -1 && (i == size(strength) || strength[stk.back()] >= strength[i])) {
                const int x = stk[size(stk) - 2] + 1;
                const int y = stk.back(); stk.pop_back();
                const int z = i - 1;
                // assert(all(strength[j] >= strength[y] for j in xrange(x, y+1)))
                // assert(all(strength[j] > strength[y] for j in xrange(y+1, z+1)))
               result = add(result, mult(strength[y], sub(mult(y - x + 1, sub(prefix[z + 1], prefix[y])), mult(z - y + 1, sub(prefix[y], prefix[max(x - 1, 0)])))));
            }
            stk.emplace_back(i);
        }
        return result;
    }
};
