// Time:  O(min(t / c1, c2 / g)) = O(sqrt(t)), c1 = max(cost1, cost2)
//                                           , c2 = min(cost1, cost2)
//                                           ,  g = gcd(c1, c2)
// Space: O(1)
// math

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };
        const auto& arithmetic_progression_sum  = [](const auto& a, const auto& d, const auto& l) {
            return (a + (a + (l - 1) * d)) * l / 2;
        };
        if (cost1 < cost2) {
            swap(cost1, cost2);
        }
        const auto& lcm = static_cast<int64_t>(cost1) / gcd(cost1, cost2) * cost2;
        const auto& d = lcm / cost2;
        int64_t result = 0;
        for (int i = 0; i <= min(total / cost1, static_cast<int>(lcm / cost1) - 1); ++i) {
            // total, cost1, cost2 = 120, 7, 5
            // => cnt decreases by a fixed value every lcm(cost1, cost2) 
            // => arithmetic progressions of cnts are as follows
            //      ----- l -----  x
            //  |   24, 17, 10, 3 120
            //  |   22, 15,  8, 1 113
            // cnt  21, 14,  7,   106
            //  |   19, 12,  5,    99
            //  |   18, 11,  4,    92
            const auto& cnt = (total - i * cost1) / cost2 + 1;
            const auto& l = ceil_divide(cnt, d);
            result += arithmetic_progression_sum(cnt, -d, l);
        }
        return result;
    }
};
