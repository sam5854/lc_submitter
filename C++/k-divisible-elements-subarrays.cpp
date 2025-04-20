// Time:  O(n^2)
// Space: O(t), t is the size of trie
// trie

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        Trie trie;
        for (int i = 0; i < size(nums); ++i) {
            trie.insert(nums, i, k, p);
        }
        return trie.count();
    }

private:
    class Trie {
    public:
        Trie() : nodes_(1) {
            
        }

        void insert(const vector<int>& nums, int i, int k, int p) {
            int curr = 0, cnt = 0;
            for (int j = i; j < size(nums); ++j) {
                cnt += (nums[j] % p == 0);
                if (cnt > k) {
                    break;
                }
                if (!nodes_[curr].count(nums[j])) {
                    nodes_[curr][nums[j]] = create_node();
                }
                curr = nodes_[curr][nums[j]];
            }
        }
    
        int count() const {
            return size(nodes_) - 1;
        }

    private:
        int create_node() {
            nodes_.emplace_back();
            return size(nodes_) - 1;
        }

        using TrieNode = unordered_map<int, int>;
        vector<TrieNode> nodes_;
    };
};
