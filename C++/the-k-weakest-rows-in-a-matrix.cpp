// Time:  O(m * n)
// Space: O(k)

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        unordered_set<int> lookup;
        for (int j = 0; j < mat[0].size(); ++j) {
            for (int i = 0; i < mat.size(); ++i) {
                if (mat[i][j] || lookup.count(i)) {
                    continue;
                }
                lookup.emplace(i);
                result.emplace_back(i);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        for (int i = 0; i < mat.size(); ++i) {
            if (lookup.count(i)) {
                continue;
            }
            lookup.emplace(i);
            result.emplace_back(i);
            if (result.size() == k) {
                break;
            }
        }
        return result;
    }
};
