// Time:  O(m * 2^m + 3^m + 2^(3 * m) * logn) = O(2^(3 * m) * logn)
// Space: O(2^(2 * m))
// better complexity for small m, super large n

class Solution {
public:
    int colorTheGrid(int m, int n) {
        if (m > n) {
            swap(m, n);
        }
        const int basis = pow(3, m - 1);
        vector<int> masks;
        backtracking(-1, -1, basis, &masks);  // Time: O(2^m), Space: O(2^m)
        assert(size(masks) == 3 * pow(2, m - 1));
        unordered_map<int, int> lookup;
        for (const auto& mask : masks) {  // Time: O(m * 2^m)
            lookup[mask] = normalize(basis, mask);
        }
        unordered_map<int, int> normalized_mask_cnt;
        for (const auto& mask : masks) {
            normalized_mask_cnt[lookup[mask]] = (normalized_mask_cnt[lookup[mask]] + 1) % MOD;
        }
        assert(size(normalized_mask_cnt) == 3 * pow(2, m - 1) / 3 / (m >= 2 ? 2 : 1));  // divided by 3 * 2 is since the first two colors are normalized to speed up performance
        unordered_map<int, vector<int>> adj;
        for (const auto& [mask, _] : normalized_mask_cnt) {  // O(3^m) leaves which are all in depth m => Time: O(3^m), Space: O(3^m)
            backtracking(mask, -1, basis, &adj[mask]);
        }
        unordered_map<int, unordered_map<int, int>> normalized_adj;
        for (const auto& [mask1, mask2s] : adj) {
            for (const auto& mask2 : mask2s) {
                normalized_adj[mask1][lookup[mask2]] = (normalized_adj[mask1][lookup[mask2]] + 1) % MOD;
            }
        }
        // divided by 3 * 2 is since the first two colors in upper row are normalized to speed up performance
        assert(accumulate(cbegin(normalized_adj), cend(normalized_adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) <= 2 * pow(3, m) / 3 / 2);
        // since first two colors in lower row which has at most 3 choices could be also normalized, lower bound is upper bound divided by at most 3
        assert(accumulate(cbegin(normalized_adj), cend(normalized_adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) >= 2 * pow(3, m) / 3 / 2 / 3);
        vector<vector<int>> matrix;
        vector<vector<int>> counts(1);
        for (const auto& [mask1, cnt] : normalized_mask_cnt) {
            matrix.emplace_back();
            for (const auto& [mask2, cnt] : normalized_mask_cnt)  {
                matrix.back().emplace_back(normalized_adj[mask1][mask2]);
            }
            counts[0].emplace_back(cnt);
        }
        const auto& result = matrixMult(counts, matrixExpo(matrix, n - 1));  // Time: O((2^m)^3 * logn), Space: O((2^m)^2)
        return accumulate(cbegin(result[0]), cend(result[0]), 0,
                          [](const auto& total, const auto& x) {
                              return (total + x) % MOD;
                          });  // Time: O(2^m)
    }

private:
    void backtracking(int mask1, int mask2, int basis, vector<int> *result) {  // Time: O(2^m), Space: O(2^m)
        if (!basis) {
            result->emplace_back(mask2);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if ((mask1 == -1 || mask1 / basis % 3 != i) && (mask2 == -1 || mask2 / (basis * 3) % 3 != i)) {
                backtracking(mask1, mask2 != -1 ? mask2 + i * basis : i * basis, basis / 3, result);
            }
        }
    }

    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < A.size(); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if (pow % 2 == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow /= 2;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % MOD + entry) % MOD;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }

    int normalize(int basis, int mask) {
        unordered_map<int, int> norm;
        int result = 0;
        for (; basis; basis /= 3) {
            int x = mask / basis % 3;
            if (!norm.count(x)) {
                norm[x] = size(norm);
            }
            result += norm[x] * basis;
        }
        return result;
    }

    static const int MOD = 1e9 + 7;
};
