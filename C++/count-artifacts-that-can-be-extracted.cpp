// Time:  O(a + d), a is the number of grids covered by artifacts, d is the size of dig
// Space: O(d)
// hash table

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_set<int> lookup;
        for (const auto& x : dig) {
            lookup.emplace(x[0] * n + x[1]);
        }
        int result = 0;
        for (const auto& x : artifacts) {
            int cnt = (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
            for (int i = x[0]; i <= x[2]; ++i) {
                for (int j = x[1]; j <= x[3]; ++j) {
                    cnt -= lookup.count(i * n + j);
                }
            }
            if (!cnt) {
                ++result;
            }
        }
        return result;
    }
};
