// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        const auto& reachable = floydWarshall(n, prerequisites);
        vector<bool> result;
        for (const auto& q : queries) {
            result.emplace_back(reachable.count(q[0] * n + q[1]));
        }
        return result;
    }

private:
    unordered_set<int> floydWarshall(int n, const vector<vector<int>>& graph) {
        unordered_set<int> reachable;
        for (const auto& connected : graph) {
            reachable.emplace(connected[0] * n + connected[1]);
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!reachable.count(i * n + j) &&
                        (reachable.count(i * n + k) && reachable.count(k * n + j))) {
                        reachable.emplace(i * n + j);
                    }
                }
            }
        }
        return reachable;
    }
};
