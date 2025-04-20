// Time:  O(n * r^2)
// Space: O(min(n * r^2, max_x * max_y))
// math, hash table

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int max_y = 0;
        for (const auto& circle : circles) {
            max_y = max(max_y, circle[1] + circle[2]);
        }
        unordered_set<int> lookup;
        for (const auto& circle : circles) {
            for (int i = -circle[2]; i <= circle[2]; ++i) {
                for (int j = -circle[2]; j <= circle[2]; ++j) {
                    if (i * i + j * j <= circle[2] * circle[2]) {
                        lookup.insert((circle[0] + i) * (max_y + 1) + (circle[1] + j));
                    }
                }
            }
        }
        return size(lookup);
    }
};
