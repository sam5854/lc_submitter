// Time:  O(r * (n + q)), r is the max of nums
// Space: O(r * n)

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        static const int INF = numeric_limits<int>::max();
        vector<vector<int>> prefix(1, vector<int>(*max_element(cbegin(nums), cend(nums)) + 1));
        for (const auto& num : nums) {
            prefix.emplace_back(prefix.back());
            ++prefix.back()[num];
        }
        vector<int> result;
        for (const auto& query : queries) {
            int min_diff = INF, prev = -1;
            for (int num = 0; num < size(prefix[0]); ++num) {
                if (!(prefix[query[0]][num] < prefix[query[1] + 1][num])) {
                    continue;
                }
                if (prev != -1) {
                    min_diff = min(min_diff, num - prev);
                }
                prev = num;
            }
            result.emplace_back((min_diff != INF) ? min_diff : -1);
        }
        return result;
    }
};
