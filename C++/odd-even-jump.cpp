// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        vector<int> idx(A.size());
        iota(idx.begin(), idx.end(), 0);
        
        sort(idx.begin(), idx.end(),
             [&](int a, int b) {
                 return A[a] != A[b] ? A[a] < A[b] : a < b;
             });
        const auto& next_higher = findNext(idx);
        sort(idx.begin(), idx.end(),
             [&](int a, int b) {
                 return A[a] != A[b] ? A[a] > A[b] : a < b;
             });
        const auto& next_lower = findNext(idx);

        vector<bool> odd(A.size()), even(A.size());
        odd.back() = even.back() = true;
        for (int i = A.size() - 2; i >= 0; --i) {
            if (next_higher[i] != -1) {
                odd[i] = even[next_higher[i]];
            }
            if (next_lower[i] != -1) {
                even[i] = odd[next_lower[i]];
            }
        }
        return count(odd.cbegin(), odd.cend(), true);
    }

private:
    vector<int> findNext(const vector<int>& idx) {
        vector<int> result(idx.size(), -1);
        vector<int> stack;
        for (const auto& i : idx) {
            while (!stack.empty() && stack.back() < i) {
                result[stack.back()] = i, stack.pop_back();
            }
            stack.emplace_back(i);
        }
        return result;
    }
};
