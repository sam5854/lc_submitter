// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for (int i = 0; i < size(matrix); ++i) {
            unordered_set<int> r, c;
            for (int j = 0; j < size(matrix[0]); ++j) {
                r.emplace(matrix[i][j]);
                c.emplace(matrix[j][i]);
            }
            if (size(r) != size(matrix[0]) || size(c) != size(matrix)) {
                return false;
            }
        }
        return true;
    }
};
