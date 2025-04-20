// Time:  O(n * nlogn + n^3 + n^2 * k) = O(n^3)
// Space: O(n * nlogn) = O(n^2 * logn)
// number theory, dp

class Solution {
public:
    int minimumChanges(string s, int k) {
        vector<vector<int>> divisors(size(s) + 1);
        for (int i = 1; i < size(divisors); ++i) {  // Time: O(nlogn), Space: O(nlogn)
            for (int j = i; j < size(divisors); j += i) {
                divisors[j].emplace_back(i);
            }
        }    
        vector<vector<unordered_map<int, int>>> dp(size(s), vector<unordered_map<int, int>>(size(s)));
        for (int l = 1; l <= size(s); ++l) {  // Time: O(n * nlogn + n^3), Space: O(n * nlogn)
            for (int left = 0; left + l - 1 < size(s); ++left) {
                const int right = left + l - 1;
                for (const auto& d : divisors[l]) {
                    int c = 0;
                    for (int i = 0; i < d; ++i) {
                        if (s[left + i] != s[right - (d - 1) + i]) {
                            ++c;
                        }
                    }
                    dp[left][right][d] = (left + d < right - d ? dp[left + d][right - d][d] : 0) + c;
                }
            }
        }
        vector<vector<int>> dp2(size(s), vector<int>(size(s), size(s)));
        for (int i = 0; i < size(s); ++i) {  // Time: O(n^2 * logn + n^2 * k), Space: O(n * k)
            for (int j = i + 1; j < size(s); ++j) {
                int c = size(s);
                for (const auto& d : divisors[j - i + 1]) {
                    if (d != j - i + 1) {
                        c = min(c, dp[i][j][d]);
                    }
                }
                dp2[i][j] = c;
            }
        }
        vector<int> dp3(size(s) + 1, size(s));
        dp3[0] = 0;
        for (int l = 0; l < k; ++l) {  // Time: O(n^2 * logn + n^2 * k), Space: O(n * k)
            vector<int> new_dp3(size(s) + 1, size(s));
            for (int i = 0; i < size(s); ++i) {
                for (int j = l * 2; j < i; ++j) {  // optimized for the fact that the length of semi-palindrome is at least 2
                    new_dp3[i + 1] = min(new_dp3[i + 1],  dp3[j] + dp2[j][i]);
                }
            }
            dp3 = move(new_dp3);
        }
        return dp3[size(s)];
    }
};
