// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countVowelSubstrings(string word) {
        static const int k = 5;
        return atLeastK(word, k);
    }

private:
    int atLeastK(const string& word, int k) {
        static const unordered_set<int> VOWELS = {'a', 'e', 'i', 'o', 'u'};

        unordered_map<int, int> cnt;
        int result = 0;
        for (int i = 0, left = 0, right = 0; i < size(word); ++i) {
            if (!VOWELS.count(word[i])) {
                cnt.clear();
                left = right = i + 1;
                continue;
            }
            ++cnt[word[i]];
            for (; size(cnt) > k - 1; ++right) {
                if (!--cnt[word[right]]) {
                    cnt.erase(word[right]);
                }
            }
            result += right - left;
        }
        return result;
    }
};
