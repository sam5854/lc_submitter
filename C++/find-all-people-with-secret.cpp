// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(begin(meetings), end(meetings), [](const auto& a, const auto& b) { return a[2] < b[2]; });
        unordered_set<int> result = {0, firstPerson};
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(meetings); ++i) {
            int x = meetings[i][0], y = meetings[i][1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
            if (i + 1 != size(meetings) && meetings[i + 1][2] == meetings[i][2]) {
                continue;
            }
            vector<int> q;
            for (const auto& [k, _] : adj) {
                if (result.count(k)) {
                    q.emplace_back(k);
                }
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (result.count(v)) {
                            continue;
                        }
                        result.emplace(v);
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            adj.clear();
        }
        return {cbegin(result), cend(result)};
    }
};
