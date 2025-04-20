// Time:  O(m * n)
// Space: O(m)
// mono stack

class Solution {
public:
    long long countSubmatrices(vector<vector<int>>& grid, int k) {
        const auto& count = [](const auto& heights) {
            int result = 0;
            vector<int> stk;
            for (int i = 0, curr = 0; i < size(heights); ++i) {
                while (!empty(stk) && heights[stk.back()] >= heights[i]) {
                    const int j = stk.back(); stk.pop_back();
                    curr -= (heights[j] - heights[i]) * (j - (!empty(stk) ? stk.back() : -1));
                }
                stk.emplace_back(i);
                curr += heights[i];
                result += curr;
            }
            return result;
        };
    
        int64_t result = 0;
        vector<int> heights(size(grid));
        for (int j = size(grid[0]) - 1; j >= 0; --j) {
            for (int i = 0; i < size(grid); ++i) {
                if (grid[i][j] > k) {
                    heights[i] = 0;
                } else if (j + 1 < size(grid[0]) && grid[i][j] >= grid[i][j + 1]) {
                    ++heights[i];
                } else {
                    heights[i] = 1;
                }
            }
            result += count(heights);
        }
        return result;
    }
};
