// Time:  O(log(min(m, n)))
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const auto& binary_search = [](int left, int right, const auto& check) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& findKthInTwoSortedArrays = [&](auto& A, auto& B, int k) {
            int m = size(A);
            int n = size(B);

            // Make sure m is the smaller one.
            if (m > n) {
                swap(m, n);
                swap(A, B);
            }

            // Find a partition of A and B
            // where min i s.t. A[i] >= B[k - 1 - i]. Thus A[i] is the (k+1)-th or above element.
            const int i = binary_search(max(k - n, 0), min(m, k) - 1, [&](int i) {
                return A[i] >= B[k - 1 - i];
            });
            // kth element would be A[i - 1] or B[k - 1 - i].
            const int Ai_minus_1 = i - 1 >= 0 ? A[i - 1] : numeric_limits<int>::min();
            const int Bj = k - 1 - i >= 0 ? B[k - 1 - i] : numeric_limits<int>::min();
            return max(Ai_minus_1, Bj);
        };

        if ((size(nums1) + size(nums2)) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (size(nums1) + size(nums2)) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (size(nums1) + size(nums2)) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (size(nums1) + size(nums2)) / 2 + 1)) / 2.0;
        }
    }
};
