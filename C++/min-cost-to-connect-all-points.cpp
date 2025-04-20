// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int result = 0, u = 0;  // we can start from any node as u
        vector<int> dist(size(points), numeric_limits<int>::max());
        unordered_set<int> lookup;
        for (int i = 0; i < size(points) - 1; ++i) {
            int x0 = points[u][0], y0 = points[u][1];
            lookup.emplace(u);
            for (int v = 0; v < size(points); ++v) {
                if (lookup.count(v)) {
                    continue;
                }
                dist[v] = min(dist[v], abs(points[v][0] - x0) + abs(points[v][1] - y0));
            }
            int val = numeric_limits<int>::max();
            for (int v = 0; v < size(dist); ++v) {
                if (dist[v] < val) {
                    val = dist[v];
                    u = v;
                }
            }
            dist[u] = numeric_limits<int>::max();  // used
            result += val;
        }
        return result;
    }
};
