// Time:  O(n * 2^n), len(sums) = 2^n
// Space: O(1)
// [proof]
// - let d = sorted_sums[0]-sorted_sums[1] and d != -d (d = 0 is trival), where one of +d/-d is the smallest positive or largest negative number of the original solution of [S1, ..., S(2^n)]
// - given Sp-d = 0 for some p in [1, 2^n] and Sq-(-d) = 0 for some q in [1, 2^n]
//   assume d is a number of the original solution of [S1, ..., S(2^n)] (the proof where -d is a number of the original solution is vice versa)
//   let Sq = x1+...+xi where 1 <= i <= n-1
//   let [d]+[x1, ..., xi]+[x(i+1), ..., x(n-1)] be the original solution
//   => new_sums([S1, ..., S(2^n)], d)
//      = subset_sums([x1, ..., xi]+[x(i+1), ..., x(n-1)])
//   if we choose -d as a number of a solution of [S1, ..., S(2^n)]
//   => new_sums([S1, ..., S(2^n)], -d)
//      = new_sums([S1, ..., S(2^n)], -(x1+...+xi))
//      = subset_sums([(-x1), ..., (-xi)]+[x(i+1), ..., x(n-1)])
//      => [-d]+[(-x1), ..., (-xi)]+[x(i+1), ..., x(n-1)] is also a solution
//
// [conclusion]
// - if new_sums with +d/-d (including d = 0) both contain zero, we can choose either one
// - if only one of new_sums with +d/-d contains zero, we can only choose the one with zero since subset_sums must contain zero
// optimized from solution4 (not using unordered_map), runtime: 188 ms

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(begin(sums), end(sums));  // Time: O(2^n * log(2^n)) = O(n * 2^n)
        int shift = 0, l = size(sums);
        vector<int> result;
        for (; n--; l /= 2) {  // log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            const int new_shift = sums[0] - sums[1];
            assert(new_shift <= 0);
            bool has_zero = false;
            for (int i = 0, j = 0, k = 0; i < l; ++i) {
                if (k < j && sums[k] == sums[i]) {  // skip shifted one
                    ++k;
                } else {
                    if (shift == sums[i] - new_shift) {
                        has_zero = true;
                    }
                    sums[j++] = sums[i] - new_shift;
                }
            }
            if (has_zero) {  // contain 0, choose this side
                result.emplace_back(new_shift);
            } else {  // contain no 0, choose another side and shift 0 offset
                result.emplace_back(-new_shift);
                shift -= new_shift;
            }
        }
        return result;
    }
};
