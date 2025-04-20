// Time:  O(n)
// Space: O(n)
// Bucket Sort Solution

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto& i : nums) {
            ++counts[i];
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& kvp : counts) {
            buckets[kvp.second].emplace_back(kvp.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = 0; j < buckets[i].size(); ++j){
                result.emplace_back(buckets[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
