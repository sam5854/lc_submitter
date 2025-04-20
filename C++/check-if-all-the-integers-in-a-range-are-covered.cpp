// Time:  O(n + r)
// Space: O(r)
// if r is small, this is better

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        static const int RANGE_SIZE = 50;

        vector<int> interval(RANGE_SIZE + 1);
        for (const auto& r : ranges) {
            ++interval[r[0] - 1];
            --interval[(r[1] - 1) + 1];
        }
        for (int i = 0, cnt = 0; i <= right - 1; ++i) {
            cnt += interval[i];
            if (i >= left - 1 && !cnt) {
                return false;
            }
        }
        return true;
    }
};
