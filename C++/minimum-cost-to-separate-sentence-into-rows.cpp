// Time:  O(s + n * k), n is the number of the word_lens
// Space: O(k)

class Solution {
public:
    int minimumCost(string sentence, int k) {
        vector<int> word_lens, dp;  // dp[i]: min cost of word_lens[-1-i:]
        for (int i = size(sentence) - 1, j = size(sentence) - 1, t = -1; i >= -1; --i) {
            if (i != -1 && sentence[i] != ' ') {
                continue;
            }
            const int l = j - i;
            j = i - 1;
            word_lens.emplace_back(l);
            dp.emplace_back(numeric_limits<int>::max());
            t += l + 1;
            if (t <= k) {
                dp.back() = 0;
                continue;
            }
            int total = l;
            for (int j = size(dp) - 2; j >= 0; --j) {
                dp.back() = min(dp.back(), dp[j] + (k - total) * (k - total));
                total += (word_lens[j] + 1);
                if (total > k) {
                    word_lens = vector<int>(cbegin(word_lens) + j, cend(word_lens));  // minimize len(word_lens) s.t. sum(word_lens) > k
                    dp = vector<int>(cbegin(dp) + j, cend(dp));
                    break;
                }
            }
        }
        return !empty(dp) ? dp.back() : 0;
    }
};
