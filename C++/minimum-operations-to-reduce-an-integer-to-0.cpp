// Time:  O(logn)
// Space: O(1)
// greedy, trick
// reference: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/solutions/3203994/java-c-python-1-line-solution/

class Solution {
public:
    int minOperations(int n) {
        return __builtin_popcount(n ^ (n * 0b11));
    }
};
