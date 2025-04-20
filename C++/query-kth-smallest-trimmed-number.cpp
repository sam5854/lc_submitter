// Time:  O(q + n * t)
// Space: O(t + n + q)
// radix sort

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int max_t = 0;
        for (int i = 0; i < size(queries); ++i) {
            max_t = max(max_t, queries[i][1]);
        }
        vector<vector<pair<int, int>>> lookup(max_t + 1);
        for (int i = 0; i < size(queries); ++i) {
            lookup[queries[i][1]].emplace_back(queries[i][0], i);
        }
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        vector<int> result(size(queries));
        for (int l = 1; l <= max_t; ++l) {
            vector<int> cnt(10);
            for (int i = 0; i < size(idxs); ++i) {
                const int d = nums[idxs[i]][size(nums[idxs[i]]) - l]- '0';
                ++cnt[d];
            }
            for (int d = 0; d < 9; ++d) {
                cnt[d + 1] += cnt[d];
            }
            vector<int> new_idxs(size(nums));
            for (int i = size(idxs) - 1; i >= 0; --i) {
                const int d = nums[idxs[i]][size(nums[idxs[i]]) - l] - '0';
                --cnt[d];
                new_idxs[cnt[d]] = idxs[i];
            }
            idxs = move(new_idxs);
            for (const auto& [k, i] : lookup[l]) {
                result[i] = idxs[k - 1];
            }
        }
        return result;
    }
};
