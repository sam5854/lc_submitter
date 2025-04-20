// Time:  O(k * nlogn)
// Space: O(n)
// sort, math

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        static const int INF = numeric_limits<int>::max();
        const auto& count = [&](const vector<int>& machine, int budget) {
            const auto& cnt = [&](int x) {
                return stock[x] / machine[x];
            };
        
            vector<int> idxs(n);
            iota(begin(idxs), end(idxs), 0);
            sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
                return cnt(a) < cnt(b);
            });
            
            int result = cnt(idxs[0]);
            for (int i = 0, prefix = 0, curr = 0, discount = 0; i < n; ++i) {
                curr += cost[idxs[i]] * machine[idxs[i]];
                discount += cost[idxs[i]] * (stock[idxs[i]] % machine[idxs[i]]);
                if (i + 1 != n && cnt(idxs[i + 1]) - cnt(idxs[i]) == 0) {
                    continue;
                }
                prefix += curr;
                budget += discount;
                curr = discount = 0;
                const auto mn = min(i + 1 < n ? (cnt(idxs[i + 1]) - cnt(idxs[i])) : INF, budget / prefix);
                if (mn == 0) {
                    break;
                }
                budget -= prefix * mn;
                result += mn;
            }
            return result;
        };

        int result = 0;
        for (const auto& machine : composition) {
            result = max(result, count(machine, budget));
        }
        return result;
    }
};
