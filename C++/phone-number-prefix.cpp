// Time:  O(l * nlogn)
// Space: O(1)
// sort

class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        sort(begin(numbers), end(numbers));
        for (int i = 0; i + 1 < size(numbers); ++i) {
            if (numbers[i + 1].starts_with(numbers[i])) {
                return false;
            }
        }
        return true;
    }
};
