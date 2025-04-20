// Time:  O(n^2)
// Space: O(n^2)
// bfs, bucket sort, union find

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        const auto& bfs = [&]() {
            vector<vector<int>> dist(size(grid), vector<int>(size(grid[0]), -1));
            vector<pair<int, int>> q;
            for (int r = 0; r < size(grid); ++r) {
                for (int c = 0; c < size(grid[0]); ++c) {
                    if (grid[r][c]) {
                        dist[r][c] = 0;
                        q.emplace_back(r, c);
                    }
                }
            }
            int d = 0;
            for (int d = 0; !empty(q); ++d) {
                vector<pair<int, int>> new_q;
                for (const auto& [r, c] : q) {
                    for (const auto& [dr, dc] : DIRECTIONS) {
                        const int nr = r + dr, nc = c + dc;
                        if (!(0 <= nr && nr < size(dist) && 0 <= nc && nc < size(dist[0]) && dist[nr][nc] == -1)) {
                            continue;
                        }
                        dist[nr][nc] = d + 1;
                        new_q.emplace_back(nr, nc);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };

        auto dist = bfs();
        vector<vector<pair<int, int>>> buckets((size(grid) - 1) + (size(grid[0]) - 1) + 1);
        for (int r = 0; r < size(grid); ++r) {
            for (int c = 0; c < size(grid[0]); ++c) {
                buckets[dist[r][c]].emplace_back(r, c);
            }
        }
        vector<vector<bool>> lookup(size(grid), vector<bool>(size(grid[0])));
        UnionFind uf(size(grid) * size(grid[0]));
        int d = size(buckets) - 1;
        for (; d >= 0; --d) {
            for (const auto& [r, c] : buckets[d]) {
                for (const auto& [dr, dc] : DIRECTIONS) {
                    const int nr = r + dr, nc = c + dc;
                    if (!(0 <= nr && nr < size(dist) && 0 <= nc && nc < size(dist[0]) && lookup[nr][nc])) {
                        continue;
                    }
                    uf.union_set(nr * size(grid[0]) + nc, r * size(grid[0]) + c);
                }
                lookup[r][c] = true;
            }
            if (uf.find_set(0 * size(grid[0]) + 0) == uf.find_set((size(grid) - 1) * size(grid[0]) + (size(grid[0]) - 1))) {
                break;
            }
        }
        return d;
    }

private:
class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n) {
            iota(begin(set_), end(set_), 0);
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            return true;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
    };
};
