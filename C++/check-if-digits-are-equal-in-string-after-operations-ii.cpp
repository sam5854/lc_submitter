// Time:  O(nlogn)
// Space: O(1)
// fast exponentiation

class Solution {
public:
    bool hasSameDigits(string s) {
        const auto& pow = [](uint64_t a, int b, int m) {  // O(logMOD) = O(1)
            a %= m;
            uint64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (result * a) % m;
                }
                a = (a * a) % m;
                b >>= 1;
            }
            return result;
        };

        const auto& check = [&](int mod) {
            const auto& decompose = [](int x, int mod) {  // x = a * mod^cnt
                int cnt = 0;
                while (x > 1 && x % mod == 0) {
                    x /= mod;
                    ++cnt;
                }
                return pair(x, cnt);
            };

            int result = 0, cnt = 0;
            int curr = 1;
            for (int i = 0; i <= size(s) - 2; ++i) {
                if (cnt == 0) {
                    result = (result + curr * (s[i] - s[i + 1])) % mod;
                }
                const auto& [x1, c1] = decompose(size(s) - 2 - i, mod);
                curr = (curr * x1) % mod;
                cnt += c1;
                const auto& [x2, c2] = decompose(i + 1, mod);
                curr = (curr * pow(x2, mod - 2, mod)) % mod;
                cnt -= c2;
            }
            return result == 0;
        };

        return check(2) && check(5);
    }
};
