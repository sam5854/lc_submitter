// Time:  O(m * n)
// Space: O(n)
// Ascending stack solution.

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int result = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }

private:
    int largestRectangleArea(const vector<int>& heights) {
        vector<int> stk = {-1};
        int res = 0;
        for (int i = 0; i <= size(heights); ++i) {
            while (stk.back() != -1 && (i == size(heights) || heights[stk.back()] >= heights[i])) {
                int last = stk.back(); stk.pop_back();
                res = max(res, heights[last] * ((i - 1) - stk.back()));
            }
            stk.emplace_back(i);
        }
        return res;
    }
};
