// Time:  O(logk + r), r is the size of result
// Space: O(k), k is the size of stepping numbers in [0, high]

class Solution {
public:
	vector<int> countSteppingNumbers(int low, int high) {
		const auto lit = lower_bound(result.cbegin(), result.cend(), low);
		const auto rit = upper_bound(result.cbegin(), result.cend(), high);
		return vector<int>(lit, rit);
	}
};
