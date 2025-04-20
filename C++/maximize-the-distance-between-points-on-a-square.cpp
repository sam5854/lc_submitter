// Time:  O(nlogn + nlogs), s = side
// Space: O(n)
// sort, binary search, greedy, two pointers, sliding window

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };
      
        vector<int64_t> p;
        for (const auto& x : points) {
            if (x[0] == 0) {
                p.emplace_back(0ll * side + x[1]);
            } else if(x[1] == side) {
                p.emplace_back(1ll * side + x[0]);
            } else if(x[0] == side) {
                p.emplace_back(2ll * side + (side - x[1]));
            } else {
                p.emplace_back(3ll * side + (side - x[0]));
            }
        }
        sort(begin(p), end(p));
        
        const auto& check = [&](int d) {
            vector<tuple<int, int, int>> intervals = {{0, 0, 1}};
            for (int right = 1, i = 0; right < size(p); ++right) {
                int left = right, cnt = 1;
                for (; i < size(intervals); ++i) {
                    const auto& [l, r, c] = intervals[i];
                    if (p[right] - p[r] < d) {
                        break;
                    }
                    if ((p[l] + 4ll * side) - p[right] >= d) {
                        if (c + 1 >= cnt) {
                            cnt = c + 1;
                            left = l;
                        }
                    }
                }
                intervals.emplace_back(left, right, cnt);
            }
            int mx = 0;
            for (const auto& [l, r, c] : intervals) {
                mx = max(mx, c);
            }
            return mx >= k;
        };

        return binary_search_right(1ll, 4ll * side / k, check);
    }
};
