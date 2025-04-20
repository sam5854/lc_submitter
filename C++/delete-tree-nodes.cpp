// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        unordered_map<int, vector<int>> children;
        for (int i = 1; i < parent.size(); ++i) {
            children[parent[i]].emplace_back(i);
        }
        return dfs(value, &children, 0).second;
    }

private:
    pair<int, int> dfs(const vector<int>& value, 
                       unordered_map<int, vector<int>> *children,
                       int x) {
        int total = value[x], count = 1;
        for (const auto& y : (*children)[x]) {
            const auto& [t, c] = dfs(value, children, y);
            total += t;
            count += t ? c : 0;
        }
        return {total, total ? count : 0};
    }
};
