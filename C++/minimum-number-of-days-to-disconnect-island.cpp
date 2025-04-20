// Time:  O(m * n)
// Space: O(m * n)
// template: https://github.com/kamyu104/GoogleCodeJam-Farewell-Rounds/blob/main/Round%20B/railroad_maintenance.py3
// Reference: https://en.wikipedia.org/wiki/Biconnected_component#Algorithms
// flood fill, tarjan's algorithm, articulation points

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        const int R = size(grid), C = size(grid[0]);
        if (count_islands(grid) != 1) {
            return 0;
        }
        vector<vector<int>> adj(R * C);
        int cnt = 0, idx = -1;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                ++cnt;
                if (idx == -1) {
                    idx = i * C + j;
                }
                for (const auto& [di, dj] : DIRECTIONS) {
                    const auto& [ni, nj] = pair(i + di, j + dj);
                    if (0 <= ni && ni < R && 0 <= nj && nj < C && grid[ni][nj] == grid[i][j]) {
                        adj[i * C + j].emplace_back(ni * C + nj);
                    }
                }
                
            }
        }
        return cnt == 1 || !empty(iter_get_articulation_points(adj, idx)) ? 1 : 2;
    }

private:
    int count_islands(const vector<vector<int>>& grid) {
        vector<vector<int>> lookup(grid.size(), vector<int>(grid[0].size()));
        int islands_cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0 || lookup[i][j]) {
                    continue;
                }
                ++islands_cnt;
                floodfill(grid, i, j, &lookup);
            }
        }
        return islands_cnt;
    }

    void floodfill(const vector<vector<int>>& grid, int i, int j, vector<vector<int>> *lookup) {
        static const vector<pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<pair<int, int>> stk = {{i, j}};
        (*lookup)[i][j] = 1;
        while (!stk.empty()) {
            auto [i, j] = stk.back(); stk.pop_back();
            for (const auto& [di, dj] : DIRECTIONS) {
                const auto& [ni, nj] = pair(i + di, j + dj);
                if (!(0 <= ni && ni < grid.size() &&
                      0 <= nj && nj < grid[0].size() &&
                      grid[ni][nj] &&
                      !(*lookup)[ni][nj])) {
                    continue;
                }
                (*lookup)[ni][nj] = 1;
                stk.emplace_back(ni, nj);
            }
        }
    }
};
