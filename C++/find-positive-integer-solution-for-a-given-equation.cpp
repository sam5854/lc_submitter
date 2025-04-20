// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        int x = 1, y = 1;
        while (customfunction.f(x, y) < z) {
            ++y;
        }
        while (y > 0) {
            while (y > 0 && customfunction.f(x, y) > z) {
                --y;
            }
            if (y > 0 && customfunction.f(x, y) == z) {
                result.push_back({x, y});
            }
            ++x;
        }
        return result;
    }
};
