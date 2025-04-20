// Time:  O(26n)
// Space: O(26)

class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        for (int i = 0; i < word.length() - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a) {
                dp[b] = max(dp[b], dp[a] - distance(a, c) + distance(b, c));
            }
        }
        int result = 0;
        for (int i = 0; i < word.length() - 1; ++i) {
            result += distance(word[i] - 'A', word[i + 1] - 'A');
        }
        return result - *max_element(dp.cbegin(), dp.cend());
    }

private:
    int distance(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};
