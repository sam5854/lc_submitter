// Time:  O(m * n)
// Space: O(m + n)
// mono stack, optimized from solution2

class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        vector<vector<int>> result(size(heights), vector<int>(size(heights[0])));
        const auto& count = [](int h, vector<int> *stk) {
            int cnt = 0;
            while (!empty(*stk) && stk->back() < h) {
                stk->pop_back();
                ++cnt;
            }
            if (!empty(*stk)) {
                ++cnt;
            }
            if (empty(*stk) || stk->back() != h) {
                stk->emplace_back(h);
            }
            return cnt;
        };

        for (int i = 0; i < size(heights); ++i) {
            vector<int> stk;
            for (int j = size(heights[0]) - 1; j >= 0; --j) {
                result[i][j] += count(heights[i][j], &stk);
            }
        }
        for (int j = 0; j < size(heights[0]); ++j) {
            vector<int> stk;
            for (int i = size(heights) - 1; i >= 0; --i) {
                result[i][j] += count(heights[i][j], &stk);
            }
        }
        return result;
    }
};
