// Time:  O(m * n * log(m * n))
// Space: O(m * n)
// Dijkstra algorithm solution

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};

        using T = tuple<int, int, int>;
        vector<vector<int>> dist(size(heights), vector<int>(size(heights[0]), numeric_limits<int>::max()));
        dist[0][0] = 0;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(0, 0, 0);
        vector<vector<int>> lookup(size(heights), vector<int>(size(heights[0])));
        while (!empty(min_heap)) {
            const auto [d, r, c] = min_heap.top(); min_heap.pop();
            if (lookup[r][c]) {
                continue;
            }
            lookup[r][c] = true;
            if (r == size(heights) - 1 && c == size(heights[0]) - 1) {
                return d;
            }
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (!(0 <= nr && nr < size(heights) &&
                      0 <= nc && nc < size(heights[0]) &&
                      !lookup[nr][nc])) {
                    continue;
                }
                int nd = max(d, abs(heights[nr][nc] - heights[r][c]));
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    min_heap.emplace(nd, nr, nc);
                }
            }
        }
        return -1;
    }
};
