// Time:  O(1)
// Space: O(1)

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        for (N = (N - 1) % 14 + 1; N > 0; --N) {
            vector<int> cells2(8);
            for (int i = 1; i < 7; ++i) {
                cells2[i] = static_cast<int>(cells[i - 1] == cells[i + 1]);
            }
            cells = move(cells2);
        }
        return cells;
    }
};
