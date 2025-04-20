// Time:  O(n) on average
// Space: O(n)
// random algorithms, variant of closest pair
// reference: https://github.com/jilljenn/tryalgo/blob/master/tryalgo/closest_points.py

class Solution {
private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();
        srand(time(0));

        vector<vector<int>> points;
        for (int i = 0; i < size(nums1); ++i) {
            points.push_back({nums1[i], nums2[i], i});
        }
        vector<int> result(3, INF);
        unordered_map<vector<int>, int, VectorHash<int>> lookup;
        for (int i = size(points) - 1; i >= 0; --i) {
            const auto& key = vector<int>{points[i][0], points[i][1]};
            if (lookup.count(key)) {
                result = min(result, vector<int>{0, i, lookup[key]});
            }
            lookup[key] = i;
        }
        if (result[0] == 0) {
            return {result[1], result[2]};
        }
        vector<int> order(size(points));
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](const auto& a, const auto& b) {
            return points[a] < points[b];
        });
        const auto& dist = [&](auto a, auto b) {
            if (a[2] > b[2]) {
                swap(a, b);
            }
            return vector<int>{abs(a[0] - b[0]) + abs(a[1] - b[1]), a[2], b[2]};
        };

        const auto& improve = [&]() {
            unordered_map<vector<int>, vector<int>, VectorHash<int>> lookup;
            for (const auto& p : points) {
                const double size = result[0] / 2.0;
                const int i = floor(p[0] / size), j = floor(p[1] / size);
                for (int ni = i - 2; ni <= i + 2; ++ni) {
                    for (int nj = j - 2; nj <= j + 2; ++nj) {
                        const auto& key = vector<int>{ni, nj};
                        if (!lookup.count(key)) {
                            continue;
                        }
                        const auto& d = dist(p, lookup[key]);
                        if (d < result) {
                            result = d;
                            return true;
                        }
                    }
                }
                lookup[vector<int>{i, j}] = p;
            }
            return false;
        };

        random_shuffle(begin(points), end(points));
        result = dist(points[0], points[1]);
        while (improve());
        return {result[1], result[2]};
    }
};
