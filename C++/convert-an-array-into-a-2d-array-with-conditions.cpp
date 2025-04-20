// Time:  O(n)
// Space: O(n)
// freq table, constructive algorithms

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            if (cnt[x] == size(result)) {
                result.emplace_back();
            }
            result[cnt[x]++].emplace_back(x);
        }
        return result;
    }
};
