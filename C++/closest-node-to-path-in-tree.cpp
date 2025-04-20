// Time:  O(n + q)
// Space: O(n + q)
// Tarjan's Offline LCA Algorithm

class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        }
        unordered_map<int, unordered_set<int>> pairs;
        for (const auto& q : query) {
            pairs[q[0]].emplace(q[1]), pairs[q[1]].emplace(q[0]);
            pairs[q[0]].emplace(q[2]), pairs[q[2]].emplace(q[0]);
            pairs[q[1]].emplace(q[2]), pairs[q[2]].emplace(q[1]);
        }
        TreeInfos tree_infos(adj, pairs);
        vector<int> result;
        for (const auto& q : query) {
            vector<int> candidates = {tree_infos.lca(q[0], q[1]),
                                      tree_infos.lca(q[0], q[2]),
                                      tree_infos.lca(q[1], q[2])};
            result.emplace_back(*max_element(cbegin(candidates), cend(candidates),
                                             [&tree_infos](const auto& a, const auto& b) {
                                                 return tree_infos.depth(a) < tree_infos.depth(b);
                                             }));
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , ancestor_(n) {
            iota(set_.begin(), set_.end(), 0);
            iota(ancestor_.begin(), ancestor_.end(), 0);  // added
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            return true;
        }

    int find_ancestor_of_set(int x) {  // added
        return ancestor_[find_set(x)];
    }

    void update_ancestor_of_set(int x) {  // added
        ancestor_[find_set(x)] = x;
    }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int> ancestor_;  // added
    };
    
    class TreeInfos {
    public:
        TreeInfos(const vector<vector<int>>& adj, const unordered_map<int, unordered_set<int>>& pairs)
         : D_(size(adj))
         , uf_(size(adj))
         , lookup_(size(adj)) {

             dfs(adj, pairs, 0, -1);
        }

        int lca(int a, int b) const {
            if (a > b) {
                swap(a, b);
            }
            return lca_.at(a).at(b);
        }

        int depth(int a) const {
            return D_[a];
        }
    
    private:
        void dfs(const vector<vector<int>>& adj,
                 const unordered_map<int, unordered_set<int>>& pairs,
                 int curr, int parent) {

            D_[curr] = (parent == -1) ? 1 : D_[parent] + 1;
            for (const auto& child : adj[curr]) {
                if (child == parent) {
                    continue;
                }
                dfs(adj, pairs, child, curr);
                uf_.union_set(child, curr);
                uf_.update_ancestor_of_set(curr);
            }
            lookup_[curr] = true;
            if (!pairs.count(curr)) {
                return;
            }
            for (const auto& v : pairs.at(curr)) {
                if (!lookup_[v]) {
                    continue;
                }
                lca_[min(curr, v)][max(curr, v)] = uf_.find_ancestor_of_set(v);
            }
        }

        vector<int> D_;
        UnionFind uf_;
        unordered_map<int, unordered_map<int, int>> lca_;
        vector<bool> lookup_;
    };
};
