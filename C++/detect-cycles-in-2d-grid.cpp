// Time:  O(m * n * α(n)) ~= O(m * n)
// Space: O(m * n)

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        UnionFind union_find(grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i && j &&
                    grid[i][j] == grid[i - 1][j] &&
                    grid[i][j] == grid[i][j - 1] &&
                    union_find.find_set(index(grid[0].size(), i - 1, j)) ==
                    union_find.find_set(index(grid[0].size(), i, j - 1))) {
                    return true;
                }
                if (i && grid[i][j] == grid[i - 1][j]) {
                    union_find.union_set(index(grid[0].size(), i - 1, j),
                                         index(grid[0].size(), i, j));
                }
                if (j && grid[i][j] == grid[i][j - 1]) {
                    union_find.union_set(index(grid[0].size(), i, j - 1),
                                         index(grid[0].size(), i, j));
                }
            }
        }
        return false;
    }

private:
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n), count_(n) {
                iota(set_.begin(), set_.end(), 0);
            }

            int find_set(const int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            void union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root != y_root) {
                    set_[min(x_root, y_root)] = max(x_root, y_root);
                    --count_;
                }
            }

            int size() const {
                return count_;
            }

        private:
            vector<int> set_;
            int count_;
    };
    
    int index(int n, int i, int j) {
        return i * n + j;
    }
};
