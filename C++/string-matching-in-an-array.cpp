// Time:  O(n + m + z) = O(n), n is the total size of patterns
//                           , m is the total size of query string
//                           , z is the number of all matched strings
//                           , O(n) = O(m) = O(z) in this problem
// Space: O(t), t is the total size of ac automata trie

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        AhoTrie trie(words);
        unordered_set<int> lookup;
        for (int i = 0; i < words.size(); ++i) {
            trie.reset();
            for (const auto& c : words[i]) {
                for (const auto& j : trie.step(c)) {
                    if (j != i) {
                        lookup.emplace(j);
                    }
                }
            }
        }
        vector<string> result;
        for (const auto& i : lookup) {
            result.emplace_back(words[i]);
        }
        return result;
    }
};
