// Time:  O(n)
// Space: O(1)
// array

class Solution {
public:
    int possibleStringCount(string word) {
        int result = size(word);
        for (int i = 0; i + 1 < size(word); ++i) {
            if (word[i] != word[i + 1]) {
                --result;
            }
        }
        return result;
    }
};
