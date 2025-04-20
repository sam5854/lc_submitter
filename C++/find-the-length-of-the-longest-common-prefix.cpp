// Time:  O((n + m) * l)
// Space: O(t)
// trie

class Solution {
private:
    class Trie {
    public:
        Trie()
         : nodes_() {
             new_node();
         }

        void add(const string& w) {
            int curr = 0;
            for (int i = 0; i < size(w); ++i) {
                const int k = w[i] - '0';
                if (nodes_[curr][k] == -1) {
                    nodes_[curr][k] = new_node();
                }
                curr = nodes_[curr][k];
            }
        }

        int query(const string& w) {
            int result = 0, curr = 0;
            for (int i = 0; i < size(w); ++i) {
                const int k = w[i] - '0';
                if (nodes_[curr][k] == -1) {
                    return i;
                }
                curr = nodes_[curr][k];
            }
            return size(w);
        }

    private:
        int new_node() {
            nodes_.emplace_back(vector<int>(10, -1));
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
    };

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for (const auto& x : arr1) {
            trie.add(to_string(x));
        }
        int result = 0;
        for (const auto& x : arr2) {
            result = max(result, trie.query(to_string(x)));
        }
        return result;
    }
};
