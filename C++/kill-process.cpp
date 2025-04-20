// Time:  O(n)
// Space: O(n)
// DFS solution.

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        unordered_map<int, unordered_set<int>> children;
        for (int i = 0; i < pid.size(); ++i) {
            children[ppid[i]].emplace(pid[i]);
        }
        killAll(kill, children, &result);
        return result;
    }

private:
    void killAll(int pid, unordered_map<int, unordered_set<int>>& children, vector<int> *killed) {
        killed->emplace_back(pid);
        for (const auto& child : children[pid]) {
            killAll(child, children, killed);
        }
    }
};
