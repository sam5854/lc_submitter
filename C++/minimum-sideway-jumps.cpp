// Time:  O(n)
// Space: O(1)
// greedy solution

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int result = 0;
        unordered_set<int> lanes = {2};
        for (int i = 0; i + 1 < size(obstacles); ++i) {
            lanes.erase(obstacles[i + 1]);
            if (!empty(lanes)) {
                continue;
            }
            ++result;
            for (int j = 1; j <= 3; ++j) {
                if (j != obstacles[i] && j != obstacles[i + 1]) {
                    lanes.emplace(j);
                }
            }
        }
        return result;
    }
};
