// Time:  O(n)
// Space: O(k)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }

private:
    int atMostK(const vector<int>& A, int K) {
        int result = 0, left = 0;
        unordered_map<int, int> count;
        for (int right = 0; right < A.size(); ++right) {
            ++count[A[right]];
            while (count.size() > K) {
                if (!--count[A[left]]) {
                    count.erase(A[left]);
                }
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};
