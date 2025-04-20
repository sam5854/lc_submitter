// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        vector<unordered_set<int>> adj(size(source));
        for (const auto& swap : allowedSwaps) {
            adj[swap[0]].emplace(swap[1]);
            adj[swap[1]].emplace(swap[0]);
        }
        vector<bool> lookup(size(source));
        int result = 0;
        for (int i = 0; i < size(source); ++i) {
            if (lookup[i]) {
                continue;
            }
            vector<int> idxs;
            iter_flood_fill(adj, i, &lookup, &idxs);
            unordered_map<int, int> source_cnt, target_cnt;
            for (const auto& i : idxs) {
                ++source_cnt[source[i]];
                ++target_cnt[target[i]];
            }
            for (const auto& [v , cnt] : source_cnt) {
                result += max(cnt - target_cnt[v], 0);
            }
        }
        return result;
    }

private:
    void iter_flood_fill(const vector<unordered_set<int>>& adj,
                         int node,
                         vector<bool> *lookup, vector<int> *idxs) {
        vector<int> stk = {node};
        while (!empty(stk)) {
            auto node = stk.back(); stk.pop_back();
            if ((*lookup)[node]) {
                continue;
            }
            (*lookup)[node] = true;
            idxs->emplace_back(node);
            for (const auto& child : adj[node]) {
                stk.emplace_back(child);
            }
        }
    }
};
