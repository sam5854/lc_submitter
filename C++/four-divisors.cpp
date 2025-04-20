// Time:  O(n * sqrt(n))
// Space: O(1)

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (const auto& num : nums) {
            vector<int> facs;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i) {
                    continue;
                }
                facs.emplace_back(i);
                if (i != num / i) {
                    facs.emplace_back(num / i);
                    if (facs.size() > 4) {
                        break;
                    }
                }
            }
            if (facs.size() == 4) {
                result += accumulate(cbegin(facs), cend(facs), 0);
            } 
        }
        return result;
    }
};
