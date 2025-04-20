// Time:  O(n + w * l)
// Space: O(n + w * l)
// rolling hash, hash table, two pointers, sliding window, dp

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        static const int MOD = 1e9 + 7, P = 131;
        vector<int64_t> power = {1};
        for (int _ = 0; _ < size(target); ++_) {
            power.emplace_back(power.back() * P % MOD);
        }
        unordered_set<int> lookup;
        for (const auto& w : words) {
            int64_t h = 0;
            for (const auto& x : w) {
                h = (h * P + (x - 'a' + 1)) % MOD;
                lookup.emplace(h);
            }
        }
        vector<int> dp(size(target) + 1);
        for (int64_t right = 0, left = 0, h = 0; right < size(target); ++right) {
            h = (h * P + (target[right] - 'a' + 1)) % MOD;
            for (; right - left + 1 >= 1 && !lookup.count(h); ++left) {
                h = ((h - (target[left] - 'a' + 1) * power[(right - left + 1) - 1]) % MOD + MOD) % MOD;
            }
            if (right - left + 1 == 0) {
                return -1;
            }
            dp[right + 1] = dp[(right - (right - left + 1)) + 1] + 1;
        }
        return dp.back();
    }
};
