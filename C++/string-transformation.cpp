// Time:  O(n + logk)
// Space: O(n)
// dp, math, kmp

class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        const int n = size(s);
        vector<int> dp(2);
        dp[1] = (((pow(n - 1, k, MOD) - pow(-1, k, MOD)) * pow(n, MOD - 2, MOD)) % MOD + MOD) % MOD;
        dp[0] = (dp[1] + pow(-1, k, MOD)) % MOD;
        int result = 0;
        for (const auto& i : KMP(s + s.substr(0, size(s) - 1), t)) {
            result = (result + dp[static_cast<int>(i != 0)]) % MOD;
        }
        return result;
    }

private:
    int64_t pow(int64_t a, int64_t b, int64_t m) {
        a %= m;
        int64_t result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }

    vector<int> KMP(const string& text, const string& pattern) {
        vector<int> result;
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                result.emplace_back(i - j);
                j = prefix[j];
            }
        }
        return result;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }

    const int MOD = 1e9 + 7;
};
