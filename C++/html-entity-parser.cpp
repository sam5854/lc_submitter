// Time:  O(n + m + z) = O(m), n is the total size of patterns
//                           , m is the total size of query string
//                           , z is the number of all matched strings
//                           , O(n) = O(1), O(z) = O(m) in this problem
// Space: O(t) = O(1), t is the total size of ac automata trie
//                   , O(t) = O(1) in this problem

class Solution {
public:
    string entityParser(string text) {
        static const vector<string> patterns = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
        static const vector<string> chars = {"\"", "'", "&", ">", "<", "/"};
        AhoTrie trie(patterns);
        vector<pair<int, int>> positions;
        for (int i = 0; i < text.length(); ++i) {
            for (const auto& j : trie.step(text[i])) {
                positions.emplace_back(i - patterns[j].length() + 1, j);
            }
        }
        string result;
        for (int i = 0, j = 0; i != text.length();) {
            if (j == positions.size() || i != positions[j].first) {                    
                result.push_back(text[i]);
                ++i;
            } else {
                result += chars[positions[j].second];
                i += patterns[positions[j].second].length();
                ++j;
            }
        }
        return result;
    }
};
