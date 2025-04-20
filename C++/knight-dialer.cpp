// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> T = {{0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                                 {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                                 {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                                 {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}};

        const auto& result = matrixExpo(T, N - 1);
        return accumulate(result.cbegin(), result.cend(), 0,
                          [&](int total, const vector<int>& row) {
                              return (total + 
                                      accumulate(row.cbegin(), row.cend(), 0,
                                                 [&](int sum, int val) {
                                                     return (sum + val) % M;
                                                 })) % M;
                          });
    }

private:
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
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % M + entry) % M;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }
    const int M = 1e9 + 7;
};
