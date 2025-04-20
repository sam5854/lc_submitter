// Time:  O(m * n)
// Space: O(m * n)
// topological sort solution

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        static const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                       {-1, 0}, {1, 0}};
        
        if (matrix.empty()) {
            return 0;
        }

        vector<vector<int>> in_degree(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                for (const auto& [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (!(0 <= ni && ni < matrix.size() &&
                          0 <= nj && nj < matrix[0].size() &&
                          matrix[ni][nj] > matrix[i][j])) {
                        continue;
                    }
                    ++in_degree[i][j];
                }
            }
        }
        vector<pair<int, int>> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!in_degree[i][j]) {
                    q.emplace_back(i, j);
                }
            }
        }
        int result = 0;
        while (!q.empty()) {
            vector<pair<int, int>> new_q;
            for (const auto& [i, j] : q) {
                for (const auto& [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (!(0 <= ni && ni < matrix.size() &&
                          0 <= nj && nj < matrix[0].size() &&
                          matrix[i][j] > matrix[ni][nj])) {
                        continue;
                    }
                    if (--in_degree[ni][nj] == 0) {
                        new_q.emplace_back(ni, nj);
                    }
                }
            }
            q = move(new_q);
            ++result;
        }
        return result;
    }
};
