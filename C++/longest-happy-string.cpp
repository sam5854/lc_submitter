// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> max_heap;
        if (a) {
            max_heap.emplace(a, 'a');
        }
        if (b) {
            max_heap.emplace(b, 'b');
        }
        if (c) {
            max_heap.emplace(c, 'c');
        }
        string result;
        while (!max_heap.empty()) {
            auto [count1, c1] = max_heap.top(); max_heap.pop();
            if (result.length() >= 2 &&
                result[result.length() - 2] == c1 &&
                result[result.length() - 1] == c1) {
                if (max_heap.empty()) {
                    return result;
                }
                auto [count2, c2] = max_heap.top(); max_heap.pop();
                result.push_back(c2);
                --count2;
                if (count2) {
                    max_heap.emplace(count2, c2);
                }
                max_heap.emplace(count1, c1);
                continue;
            }
            result.push_back(c1);
            --count1;
            if (count1) {
                max_heap.emplace(count1, c1);
            }
        }
        return result;
    }
};
