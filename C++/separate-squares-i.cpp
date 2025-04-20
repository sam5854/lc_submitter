// Time:  O(nlogn)
// Space: O(n)
// sort, line sweep

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int>> events;
        for (const auto& s : squares) {
            events.emplace_back(s[1]       , +1, s[2]);
            events.emplace_back(s[1] + s[2], -1, s[2]);
        }
        sort(begin(events), end(events), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b);
        });
        double total = 0, curr = 0;
        int prev = get<0>(events[0]);
        for (const auto& [y, v, l] : events) {
            if (y != prev) {
                total += (y - prev) * curr;
                prev = y;
            }
            curr += l * v;
        }
        const double expect = total / 2.0;
        total = 0, curr = 0;
        prev = get<0>(events[0]);
        for (const auto& [y, v, l] : events) {
            if (y != prev) {
                if (total + (y - prev) * curr >= expect) {
                    break;
                }
                total += (y - prev) * curr;
                prev = y;
            }
            curr += l * v;
        }
        return prev + (expect - total) / curr; 
    }
};
