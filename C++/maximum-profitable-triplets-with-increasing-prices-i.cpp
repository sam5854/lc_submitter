// Time:  O(nlogn)
// Space: O(n)
// prefix sum, bst, binary search, mono stack

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        static const int NEG_INF = numeric_limits<int>::min();

        const auto& query = [](const auto& bst, const auto& k) {
            const auto it = bst.lower_bound(pair(k, 0));
            return it != begin(bst) ? prev(it)->second : NEG_INF;
        };

        const auto& update = [](auto& bst, const auto& k, const auto& v) {
            const auto it = bst.lower_bound(pair(k, 0));
            if (it != end(bst) && it->first == k) {
                if (!(it->second < v)) {
                    return;
                }
                bst.erase(it);
            } else if (!(it == begin(bst) || prev(it)->second < v)) {
                return;
            }
            const auto [jt, _] = bst.emplace(k, v);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        };

        int result = NEG_INF;
        set<pair<int, int>> bst1, bst2;
        for (int i = 0; i < size(prices); ++i) {
            const int mx2 = query(bst2, prices[i]);
            if (mx2 != NEG_INF) {
                result = max(result, mx2 + profits[i]);
            }
            update(bst1, prices[i], profits[i]);
            const int mx1 = query(bst1, prices[i]);
            if (mx1 != NEG_INF) {
                update(bst2, prices[i], mx1 + profits[i]);
            }
        }
        return result != NEG_INF ? result : -1;
    }
};
