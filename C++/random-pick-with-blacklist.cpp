// Time:  ctor: O(b)
//        pick: O(1)
// Space: O(b)

class Solution {
public:
    Solution(int N, vector<int> blacklist) :
        n_(N - blacklist.size()) {
        unordered_set<int> whitelist;
        for (int i = n_; i < N; ++i) {
            whitelist.emplace(i);
        }
        for (const auto& black : blacklist) {
            whitelist.erase(black);
        }
        auto white = whitelist.cbegin();
        for (const auto& black : blacklist) {
            if (black < n_) {
                lookup_[black] = *(white++);
            }
        }
    }

    int pick() {
        int index = rand() % n_;
        return lookup_.count(index) ? lookup_[index] : index;
    }

private:
    int n_;
    unordered_map<int, int> lookup_;
};
