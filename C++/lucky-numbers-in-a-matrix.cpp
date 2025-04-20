// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rows;
        for (const auto& row : matrix) {
            rows.emplace_back(*min_element(row.cbegin(), row.cend()));
        }
        vector<int> cols;
        for (int c = 0; c < matrix[0].size(); ++c) {
            int max_cell = 0;
            for (int r = 0; r < matrix.size(); ++r) {
                max_cell = max(max_cell, matrix[r][c]);
            }
            cols.emplace_back(max_cell);
        }
        vector<int> result;
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                if (rows[r] == cols[c]) {
                    result.emplace_back(matrix[r][c]);
                }
            }
        }
        return result;
    }
};
