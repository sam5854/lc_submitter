// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int result = 0, right = numeric_limits<int>::min();
        for (const auto& x : intervals) {
            if (x[0] < right) {
                ++result;
            } else {
                right = x[1];
            }
        }
        return result;
    }
};
