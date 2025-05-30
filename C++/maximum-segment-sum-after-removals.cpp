// Time:  O(n)
// Space: O(n)
// union find

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        vector<long long> result(size(nums));
        vector<bool> lookup(size(nums));
        UnionFind uf(nums);
        for (int i = size(removeQueries) - 1; i >= 1; --i) {
            const int q = removeQueries[i];
            lookup[q] = true;
            if (q - 1 >= 0 && lookup[q - 1]) {
                uf.union_set(q - 1, q);
            }
            if (q + 1 < size(lookup) && lookup[q + 1]) {
                uf.union_set(q, q + 1);
            }
            result[i - 1] = max(result[i], uf.total(q));
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(const vector<int>& nums)
         : set_(size(nums))
         , rank_(size(nums))
         , size_(cbegin(nums), cend(nums))  {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            size_[y] += size_[x];
            return true;
        }

        long long total(int x) {
            return size_[find_set(x)];
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<long long> size_;
    };
};
