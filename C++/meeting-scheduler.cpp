// Time:  O(n) ~ O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<pair<int, int>> min_heap;
        for (const auto& slot : slots1) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace_back(slot[0], slot[1]);
            }
        }
        for (const auto& slot : slots2) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace_back(slot[0], slot[1]);
            }
        }
        make_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(n)
        while (min_heap.size() > 1) {
            pop_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(logn)
            const auto left = min_heap.back();
            min_heap.pop_back();
            pop_heap(min_heap.begin(), min_heap.end(), greater<>());
            const auto right = min_heap.back();
            min_heap.pop_back();
            min_heap.emplace_back(right);
            push_heap(min_heap.begin(), min_heap.end(), greater<>());
            if (left.second - right.first >= duration) {
                return {right.first, right.first + duration};
            }
        }
        return {};
    }
};
