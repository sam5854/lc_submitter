// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result(size(heights));
        vector<int> stk;
        for (int i = 0; i < size(heights); ++i) {
            while (!empty(stk) && heights[stk.back()] < heights[i]) {
                ++result[stk.back()]; stk.pop_back();
            }
            if (!empty(stk)) {
                ++result[stk.back()];
            }
            if (!empty(stk) && heights[stk.back()] == heights[i]) {
                stk.pop_back();
            }
            stk.emplace_back(i);
        }
        return result;
    }
};
