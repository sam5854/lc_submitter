// Time:  O(n)
// Space: O(n)
// Hash solution.

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return true;
        }
        unordered_map<int, unordered_set<int>> groups_by_y;
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        for (const auto& p : points) {
            groups_by_y[p.second].emplace(p.first);
            left = min(left, p.first);
            right = max(right, p.first);
        }
        const auto mid = left + right;
        for (const auto& kvp : groups_by_y) {
            for (const auto& x : kvp.second) {
                if (kvp.second.count(mid - x) == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
