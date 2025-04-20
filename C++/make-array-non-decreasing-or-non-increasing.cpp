// Time:  O(nlogn)
// Space: O(n)
// greedy, heap

class Solution {
public:
    int convertArray(vector<int>& nums) {
        const auto& f = [](const auto& begin, const auto& end) {
            int result = 0;
            priority_queue<int> max_heap;
            for (auto it = begin; it != end; ++it) {
                if (!empty(max_heap) && *it < max_heap.top()) {
                    result += max_heap.top() - *it; max_heap.pop();
                    max_heap.emplace(*it);
                }
                max_heap.emplace(*it);
            }
            return result;
        };
        
        return min(f(cbegin(nums), cend(nums)), f(crbegin(nums), crend(nums)));
    }    
};
