// Time:  O(n + m)
// Space: O(n + m)
// kmp, two pointers (three pointers)

class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
        static const int INF = numeric_limits<int>::max();

        const auto& KMP = [](const auto& text, const auto& pattern) {
            const auto& getPrefix = [](const auto& pattern) {
                vector<int> prefix(size(pattern), -1);
                int j = -1;
                for (int i = 1; i < size(pattern); ++i) {
                    while (j != -1 && pattern[j + 1] != pattern[i]) {
                        j = prefix[j];
                    }
                    if (pattern[j + 1] == pattern[i]) {
                        ++j;
                    }
                    prefix[i] = j;
                }
                return prefix;
            };

            vector<int> result;
            if (empty(pattern)) {
                result.resize(size(text) + 1);
                iota(begin(result), end(result), 0);
                return result;
            }
            const vector<int> prefix = getPrefix(pattern);
            int j = -1;
            for (int i = 0; i < size(text); ++i) {
                while (j > -1 && pattern[j + 1] != text[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == text[i]) {
                    ++j;
                }
                if (j == size(pattern) - 1) {
                    result.emplace_back(i - j);
                    j = prefix[j];
                }
            }
            return result;
        };

        const int i = p.find('*');
        const auto& a = p.substr(0, i);
        const int j = p.find('*', i + 1);
        const auto& b = p.substr(i + 1, j - (i + 1));
        const auto& c = p.substr(j + 1);
        const int n = size(s), la = size(a), lb = size(b), lc = size(c);
        int result = INF;
        const auto& idxs1 = KMP(s, b);
        const auto& idxs2 = KMP(s, c);
        int x = 0, y = 0;
        for (const auto& i : KMP(s, a)) {
            for (; x < size(idxs1) && idxs1[x] < i + la; ++x);
            if (x == size(idxs1)) {
                break;
            }
            for (; y < size(idxs2) && idxs2[y] < idxs1[x] + lb; ++y);
            if (y == size(idxs2)) {
                break;
            }
            result = min(result, (idxs2[y] + lc) - i);
        }
        return result != INF ? result : -1;
    }
};
