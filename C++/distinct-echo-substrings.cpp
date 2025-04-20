// Time:  O(n^2 + d), d is the duplicated of result substrings size
// Space: O(r), r is the size of result substrings set

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> result;
        int l = text.length() - 1;
        for (int i = 0; i < l; ++i)  {  // aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefabcdefabcdef
            const auto& substr_len = KMP(text, i, &result);
            if (substr_len != numeric_limits<int>::max()) {
                l = min(l, i + substr_len);
            }
        }
        return result.size();
    }

private:
    int KMP(const string& text, int l, unordered_set<string> *result) {
        vector<int> prefix(text.length() - l, -1);
        int j = -1;
        for (int i = 1; i < prefix.size(); ++i) {
            while (j > -1 && text[l + j + 1] != text[l + i]) {
                j = prefix[j];
            }
            if (text[l + j + 1] == text[l + i]) {
                ++j;
            }
            prefix[i] = j;
            if ((j + 1) && (i + 1) % ((i + 1) - (j + 1)) == 0 &&
                (i + 1) / ((i + 1) - (j + 1)) % 2 == 0) {
                result->emplace(text.substr(l, i + 1));
            }
        }
        return (prefix.back() + 1 && (prefix.size() % (prefix.size() - (prefix.back() + 1)) == 0))
               ? (prefix.size() - (prefix.back() + 1))
               : numeric_limits<int>::max();
    }
};
