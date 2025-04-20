// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        for (int i = 0; i < size(heights); ++i) {
            while (!empty(result) && heights[result.back()] <= heights[i]) {
                result.pop_back();
            }
            result.emplace_back(i);
        }
        return result;
    }
};
