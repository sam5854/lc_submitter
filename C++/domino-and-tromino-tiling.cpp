// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    int numTilings(int N) {
        vector<vector<int>> T{{1, 0, 0, 1},  // #(|) = #(|) + #(=)
                              {1, 0, 1, 0},  // #(「) = #(|) + #(L)
                              {1, 1, 0, 0},  // #(L) = #(|) + #(「)
                              {1, 1, 1, 0}}; // #(=) = #(|) + #(「) + #(L)
        return matrixMult({{1, 0, 0, 0}}, matrixExpo(T, N))[0][0];  // [a0, a(-1), a(-2), a(-3)] * T^N
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
