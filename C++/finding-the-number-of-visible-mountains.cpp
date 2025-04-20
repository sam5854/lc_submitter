// Time:  O(nlogn)
// Space: O(1)
// math, sort

class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        sort(begin(peaks), end(peaks), [](const auto& a, const auto& b) {
             const int x1 = a[0], y1 = a[1];
             const int x2 = b[0], y2 = b[1];
             return x1 - y1 != x2 - y2 ? x1 - y1 < x2 - y2 : x1 + y1 > x2 + y2;  // rotate points by 45 degrees and we only care the largest new y in the same new x
        });
        
        int result = 0;
        for (int i = 0, mx = 0; i < size(peaks); ++i) {
            if (peaks[i][0] + peaks[i][1] <= mx) {
                continue;
            }
            mx = peaks[i][0] + peaks[i][1];
            if (i + 1 == size(peaks) || peaks[i + 1] != peaks[i]) {
                ++result;
            }
        }
        return result;
    }
};
