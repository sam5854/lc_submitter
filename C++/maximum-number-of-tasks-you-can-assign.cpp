// Time:  O(n * (logn)^2)
// Space: O(n)

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers));
        int left = 1, right = min(size(tasks), size(workers));
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(tasks, workers, pills, strength, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const vector<int>& tasks, const vector<int>& workers,
               int pills, int strength,
               int x) {

        multiset<int> t(cbegin(tasks), cbegin(tasks) + x);
        for (int i = size(workers) - x; i < size(workers); ++i) {  // enumerate from the weakest worker to the strongest worker, greedily assign him to the hardest task which he can do
            auto it = t.upper_bound(workers[i]);
            if (it != begin(t)) {
                t.erase(prev(it));
                continue;
            }
            if (pills) {
                it = t.upper_bound(workers[i] + strength);
                if (it != begin(t)) {
                    t.erase(prev(it));
                    --pills;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};
