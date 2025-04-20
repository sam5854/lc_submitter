// Time:  precompute: O(max_r^2 * log(max_r))
//        runtime:    O(n + r^2)
// Space: O(max_r^2)
// number theory, mobius function, principle of inclusion-exclusion

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int mx = ranges::max(nums);
        vector<int> cnt(mx + 1);
        for (const auto& x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= mx; ++i) {
            for (int j = i + i; j <= mx; j += i) {
                cnt[i] = (cnt[i] + cnt[j]) % MOD;
            }
        }
        vector<vector<int>> f(mx + 1, vector<int>(mx + 1));
        for (int g1 = 1; g1 <= mx; ++g1) {
            for (int g2 = g1; g2 <= mx; ++g2) {
                const int l = LCM[g1][g2];
                const int c = l < size(cnt) ? cnt[l] : 0;
                const int c1 = cnt[g1], c2 = cnt[g2];
                f[g1][g2] = f[g2][g1] = ((static_cast<int64_t>(POW3[c]) * POW2[(c1 - c) + (c2 - c)] - POW2[c1] - POW2[c2] + 1) % MOD + MOD) % MOD;
            }
        }
        const auto& count = [&](int g) {
            int result = 0;
            for (int i = 1; i <= mx / g; ++i) {
                for (int j = 1; j <= mx / g; ++j) {
                    result = ((result + MU[i] * MU[j] * f[i * g][j * g]) % MOD + MOD) % MOD;
                }
            }
            return result;
        };
    
        int result = 0;
        for (int g = 1; g <= mx; ++g) {  // Time: O(mx^2 * (1 + 1/4 + 1/9 + ... + (1/mx)^2))) = O(mx^2 * pi^2/6), see https://en.wikipedia.org/wiki/Basel_problem
            result = (result + count(g)) % MOD;
        }
        return result;
    }
};
