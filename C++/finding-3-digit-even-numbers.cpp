// Time:  O(1) ~ O(n), n is 10^3
// Space: O(1)

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10);
        for (const auto& d : digits) {
            ++cnt[d];
        }
        vector<int> result, curr;
        backtracking(&curr, &cnt, &result);
        return result;
    }

private:
    void backtracking(vector<int> *curr, vector<int> *cnt, vector<int> *result) {
        static const int k = 3;
        if (size(*curr) == k) {
            result->emplace_back(accumulate(cbegin(*curr), cend(*curr), 0,
                                            [](const auto& total, const auto& x) {
                                                return total * 10 + x;
                                            }));
            return;
        }
        for (int i = 0; i < size(*cnt); ++i) {
            if ((*cnt)[i] == 0 ||
                (empty(*curr) && (i == 0)) ||
                (size(*curr) == k - 1 && i % 2 != 0)) {
                continue;
            }
            --(*cnt)[i];
            curr->emplace_back(i);
            backtracking(curr, cnt, result);
            curr->pop_back();
            ++(*cnt)[i];
        }
    }
};
