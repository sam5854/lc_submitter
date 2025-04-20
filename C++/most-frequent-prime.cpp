// Time:  precompute: O(10^MAX_N_M)
//        runtime:    O(n * m * (n + m))
// Space: O(10^MAX_N_M + n * m * (n + m))
// number theory, freq table

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        const auto& numbers = [&](int i, int j, int di, int dj) {
            vector<int> result;
            for (int curr = 0; 0 <= i && i < size(mat) && 0 <= j && j < size(mat[0]); i += di, j += dj) {
                curr = curr * 10 + mat[i][j];
                result.emplace_back(curr);
            }
            return result;
        };

        unordered_map<int, int> cnt;
        for (int i = 0; i < size(mat); ++i) {
            for (int j = 0; j < size(mat[0]); ++j) {
                for (const auto& [di, dj] : DIRECTIONS) {
                    for (const auto& x : numbers(i, j, di, dj)) {
                        if (x > 10 && SPF[x] == x) {
                            ++cnt[x];
                        }
                    }
                }
            }
        }
        pair<int, int> result = {0, -1};
        for (const auto& [k, v] : cnt) {
            result = max(result, pair(v, k));
        }
        return result.second;
    }
};
