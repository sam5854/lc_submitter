// Time:  O((n * C(c, min(c, k))) * 2^n)
// Space: O(2^n)
// concise dp solution

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> reqs(n);
        for (const auto& d : dependencies) {
            reqs[d[1] - 1] |= 1 << (d[0] - 1);
        }
        vector<int> dp(1 << n, n);
        dp[0] = 0;
        for (int mask = 0; mask < dp.size(); ++mask) {
            vector<int> candidates;
            for (int v = 0; v < n; ++v) {
                if ((mask & (1 << v)) == 0 && (mask & reqs[v]) == reqs[v]) {
                    candidates.emplace_back(v);
                }
            }
            const auto r = min(int(candidates.size()), k);
            combinations(candidates.size(), min(int(candidates.size()), k), 
                         [&dp, &mask, &candidates](const vector<int>& idxs) {
                             auto new_mask = mask;
                             new_mask |= accumulate(cbegin(idxs), cend(idxs), 0,
                                                    [&candidates](const auto& a, const auto& b) {
                                                        return a | (1 << candidates[b]);
                                                    });
                             dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
                         });
        }
        return dp.back();
    }

private:
    void combinations(int n, int k, const function<void (const vector<int>&)>& callback) {
        static const auto& next_pos =
            [](const auto& n, const auto& k, const auto& idxs) {
                int i = k - 1;
                for (; i >= 0; --i) {
                    if (idxs[i] != i + n - k) {
                        break;
                    }
                }
                return i;
            };
    
        vector<int> idxs(k);
        iota(begin(idxs), end(idxs), 0);
        callback(idxs);
        for (int i; (i = next_pos(n, k, idxs)) >= 0;) {
            ++idxs[i];
            for (int j = i + 1; j < k; ++j) {
                idxs[j] = idxs[j - 1] + 1;
            }
            callback(idxs);
        }
    }
};
