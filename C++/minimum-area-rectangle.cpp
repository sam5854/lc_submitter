// Time:  O(n^1.5) on average
//        O(n^2) on worst
// Space: O(n)

class Solution {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> x_set, y_set;
        for (const auto& point : points) {
            x_set.emplace(point[0]);
            y_set.emplace(point[1]);
        }
        map<int, vector<int>> p;
        if (x_set.size() > y_set.size()) {
            for (const auto& point : points) {
                p[point[0]].emplace_back(point[1]);
            }
        } else {
            for (const auto& point : points) {
                p[point[1]].emplace_back(point[0]);
            }
        }

        unordered_map<pair<int, int>, int, PairHash<int>> lookup;
        int result = numeric_limits<int>::max();
        for (const auto& kvp : p) {
            auto x = kvp.first;
            sort(p[x].begin(), p[x].end());
            for (int j = 0; j < p[x].size(); ++j) {
                for (int i = 0; i < j; ++i) {
                    int y1 = p[x][i], y2 = p[x][j];
                    if (lookup.count(make_pair(y1, y2))) {
                        result = min(result, (x - lookup[make_pair(y1, y2)]) * abs(y2 - y1));
                    }
                    lookup[make_pair(y1, y2)] = x;
                }
            }
        }
        return result != numeric_limits<int>::max() ? result : 0;
    }
};
