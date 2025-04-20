// Time:  O(n)
// Space: O(n)
// dfs solution with stack

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                children[manager[i]].emplace_back(i);
            }
        }
 
        int result = 0;
        vector<pair<int, int>> stk = {{headID, 0}};
        while (!stk.empty()) {
            auto [node, curr] = stk.back(); stk.pop_back();
            curr += informTime[node];
            result = max(result, curr);
            if (!children.count(node)) {
                continue;
            }
            for (const auto& child : children.at(node)) {
                stk.emplace_back(child, curr);
            }
        }
        return result;
    }
};
