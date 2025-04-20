// Time:  O(logn)
// Space: O(1)
// bit manipulation

class Solution {
public:
    int minChanges(int n, int k) {
        return (n & k) == k ? __builtin_popcount(n ^ k) : -1;
    }
};
