// Time:  O(nlogn + nlogr) = O(nlogr), r = max(nums)
// Space: O(t)
// bit manipulation, greedy, trie, sort, two pointers

class Solution {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_() {
             new_node();
         }

        void update(int num, int d) {
            int curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                int x = num >> i;
                if (nodes_[curr][x & 1] == -1) {
                    nodes_[curr][x & 1] = new_node();
                }
                curr = nodes_[curr][x & 1];
                cnts_[curr] += d;
            }
        }

        int query(int num) {
            int result = 0, curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                result <<= 1;
                const int x = num >> i;
                if (nodes_[curr][1 ^ (x & 1)] != -1 && cnts_[nodes_[curr][1 ^ (x & 1)]]) {
                    result |= 1;
                    curr = nodes_[curr][1 ^ (x & 1)];
                } else {
                    curr = nodes_[curr][x & 1];
                }
            }
            return result;
        }

    private:
        int new_node() {
            nodes_.push_back(array<int, 2>{-1, -1});
            cnts_.emplace_back(0);
            return size(nodes_) - 1;
        }

        const int bit_length_;
        vector<array<int, 2>> nodes_;
        vector<int> cnts_;
    };

public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(begin(nums), end(nums));
        Trie trie(bit_length(nums.back()));
        int result = 0;
        for (int i = 0, j = 0; i < size(nums); ++i) {
            trie.update(nums[i], +1);
            while (!(nums[i] <= 2 * nums[j])) {
                trie.update(nums[j++], -1);
            }
            result = max(result, trie.query(nums[i]));
        }
        return result;
    }

private:
    int bit_length(int x) {
        return (x ? std::__lg(x) : -1) + 1;
    }
};
