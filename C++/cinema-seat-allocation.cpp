// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_map<int, bool>> lookup;
        for (const auto& seat : reservedSeats) {
            if (2 <= seat[1] && seat[1] <= 5) {
                lookup[seat[0]][0] = true;
            }
            if (4 <= seat[1] && seat[1] <= 7) {
                lookup[seat[0]][1] = true;
            }
            if (6 <= seat[1] && seat[1] <= 9) {
                lookup[seat[0]][2] = true;
            }
        }
        int result = 2 * n;
        for (auto& [_, reserved] : lookup) {
            if (!reserved[0] && !reserved[2]) {
                continue;
            }
            if (!reserved[0] || !reserved[1] || !reserved[2]) {
                --result;
                continue;
            }
            result -= 2;
        }
        return result;
    }
};
