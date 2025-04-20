// Time:  O(nlogn + n * k^2)
// Space: O(n * k^2)
// dp, binary search

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        static const int K = 4;
        map<tuple<int, int, int>, int> lookup;
        for (int i = 0; i < size(intervals); ++i) {
            const int l = intervals[i][0];
            const int r = intervals[i][1];
            const int w = intervals[i][2];
            if (!lookup.count(tuple(r, l, w))) {
                lookup[tuple(r, l, w)] = i;
            }
        }
        vector<tuple<int, int, int>> sorted_intervals;
        for (const auto& [k, _] : lookup) {
            sorted_intervals.emplace_back(k);
        }
        vector<vector<pair<int64_t, vector<int>>>> dp(size(sorted_intervals) + 1, vector<pair<int64_t, vector<int>>>(K + 1));
        for (int i = 0; i + 1 < size(dp); ++i) {
            const int j = distance(cbegin(sorted_intervals), upper_bound(cbegin(sorted_intervals), cend(sorted_intervals), tuple(get<1>(sorted_intervals[i]), 0, 0))) - 1;
            const int idx = lookup[sorted_intervals[i]];
            for (int k = 1; k < size(dp[i]); ++k) {
                auto new_dp = pair(get<0>(dp[j + 1][k - 1]) - get<2>(sorted_intervals[i]), get<1>(dp[j + 1][k - 1]));
                auto& arr = get<1>(new_dp);
                arr.insert(upper_bound(begin(arr), end(arr), idx), idx);
                dp[i + 1][k] = min(dp[i][k], new_dp);
            }
        }
        return get<1>(dp[size(sorted_intervals)][K]);
    }
};
