// Time:  O(n * l + m), n is the number of patterns
//                    , l is the max length of patterns
//                    , m is the length of word     
// Space: O(t)        , t is the total size of ac automata trie
// ac automata solution

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto trie = AhoTrie(patterns);
        return accumulate(cbegin(word), cend(word), 0,
                          [&trie](int total, const auto& x) {
                              return total + size(trie.step(x));
                          });
    }
};
