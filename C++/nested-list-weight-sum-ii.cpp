// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for (const auto& list : nestedList) {
            depthSumInverseHelper(list, 0, &result);
        }

        int sum = 0;
        for (int i = result.size() - 1; i >= 0; --i) {
            sum += result[i] * (result.size() - i);
        }
        return sum;
    }

private:
    void depthSumInverseHelper(const NestedInteger &list, int depth, vector<int> *result) {
        if (result->size() < depth + 1) {
            result->emplace_back(0);
        }
        if (list.isInteger()) {
            (*result)[depth] += list.getInteger();
        } else {
            for (const auto& l : list.getList()) {
                depthSumInverseHelper(l, depth + 1, result);
            }
        }
    }
};
