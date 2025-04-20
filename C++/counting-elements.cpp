// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> lookup(cbegin(arr), cend(arr));
        return count_if(cbegin(arr), cend(arr),
                        [&lookup](const auto& x) {
                            return lookup.count(x + 1);
                        });
    }
};
