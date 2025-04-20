// Time:  O(nlogd)
// Space: O(d)
// fastest and less verbose
// sliding window, heap

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        const auto& get_top = [](auto& heap, auto& total, const int d) {
            while (-heap.top().second < d) {
                heap.pop();
                --total;
            }
            return heap.top();
        };

        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int total1 = 0, total2 = 0;
        int64_t mn = INF, curr = 0;
        for (int i = 1; i < size(nums); ++i) {
            max_heap.emplace(nums[i], -i);
            curr += nums[i];
            if (i > k - 1) {
                const auto [x, idx] = get_top(max_heap, total1, i - (1 + dist)); max_heap.pop();
                curr -= x;
                min_heap.emplace(x, idx);
            }
            if (i > 1 + dist) {
                if (get_top(min_heap, total2, i - (1 + dist)) <= pair(nums[i - (1 + dist)], -(i - (1 + dist)))) {
                    lazy_delete(min_heap, total2, i - (1 + dist));
                } else {
                    lazy_delete(max_heap, total1, i - (1 + dist));                    
                    curr -= nums[i - (1 + dist)] - min_heap.top().first;
                    max_heap.emplace(min_heap.top()); min_heap.pop();
                }
            }
            if (i >= k - 1) {
                mn = min(mn, curr);
            }
        }
        return nums[0] + mn;
    }

private:
    template<typename T>
    void lazy_delete(T& heap, int& total, const int d) {
        ++total;
        if (total <= size(heap) - total) {
            return;
        }
        T new_heap;
        while (!empty(heap)) {
            const auto x = heap.top(); heap.pop();
            if (-x.second <= d) {
                --total;
                continue;
            }
            new_heap.emplace(x);
        }
        heap = move(new_heap);
    }
};
