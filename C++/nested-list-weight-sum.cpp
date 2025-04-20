// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSumHelper(nestedList, 1);
    }

private:
    int depthSumHelper(const vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (const auto& list : nestedList) {
            if (list.isInteger()) {
                sum += list.getInteger() * depth;
            } else {
                sum += depthSumHelper(list.getList(), depth + 1);
            }
        }
        return sum;
    }
};
