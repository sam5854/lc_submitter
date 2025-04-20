// Time:  O(n + m + z), n is the total size of patterns
//                    , m is the total size of query string
//                    , z is the number of all matched strings
// Space: O(t), t is the total size of ac automata trie

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        for (auto& word : words) {
            reverse(word.begin(), word.end());
        }
        AhoTrie trie(words);
        vector<vector<int>> result;
        for (int i = text.length() - 1; i >= 0; --i) {
            for (const auto& j : trie.step(text[i])) {
                result.push_back({i, i + words[j].length() - 1});
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
