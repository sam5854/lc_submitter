// Time:  O(n * l)
// Space: O(n)

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int result = 0;
        unordered_set<int> unsorted;
        for (int i = 0; i < A.size() - 1; ++i) {
            unsorted.emplace(i);
        }
        for (int j = 0; j < A[0].size(); ++j) {
            if (any_of(unsorted.begin(), unsorted.end(),
                       [&](int i) {
                           return A[i][j] > A[i + 1][j];
                       })
               ) {
                ++result;
            } else {
                unordered_set<int> tmp(unsorted);
                for (const auto& i : tmp) {
                    if (A[i][j] < A[i + 1][j]) {
                        unsorted.erase(i);
                    }
                }
            }
        }
        return result;
    }
};
