// Time:  O(nlogn)
// Space: O(n)
// heap

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> result;
        unordered_map<int, int64_t> cnt;
        priority_queue<pair<int64_t, int>> max_heap;
        for (int i = 0; i < size(nums); ++i) {
            cnt[nums[i]] += freq[i];
            max_heap.emplace(cnt[nums[i]], nums[i]);
            while (!empty(max_heap) && max_heap.top().first != cnt[max_heap.top().second]) {
                max_heap.pop();
            }
            result.emplace_back(!empty(max_heap) ? max_heap.top().first : 0);
        }
        return result;
    }
};
