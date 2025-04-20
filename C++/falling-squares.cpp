// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> result;
        map<int, int> heights;
        int maxH = heights[-1] = 0;
        for (const auto& p : positions) {
            auto it0 = heights.upper_bound(p[0]);
            auto it1 = heights.lower_bound(p[0] + p[1]);
            int h0 = prev(it0)->second;
            int h1 = prev(it1)->second;
            for (auto it = it0; it != it1; ++it) {
                h0 = max(h0, it->second);
            }
            heights.erase(it0, it1);
            heights[p[0]] = h0 + p[1];
            heights[p[0] + p[1]] = h1;
            maxH = max(maxH, h0 + p[1]);
            result.emplace_back(maxH);
        }
        return result;
    }
};
