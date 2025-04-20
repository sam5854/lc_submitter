// Time:  O(n) on average
// Space: O(1)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        static const auto& dist = [](const vector<int>& v) {
            return v[0] * v[0] + v[1] * v[1];
        };
        nth_element(points.begin(), points.begin() + K - 1, points.end(),
                    [&](const vector<int>& a, const vector<int>& b) {
                        return dist(a) < dist(b);
                    });
        return {points.cbegin(), points.cbegin() + K};
    }
};
