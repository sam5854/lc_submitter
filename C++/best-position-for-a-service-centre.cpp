// Time:  O(n * iter), iter is the number of iterations
// Space: O(1)
// see reference:
// - https://en.wikipedia.org/wiki/Geometric_median
// - https://wikimedia.org/api/rest_v1/media/math/render/svg/b3fb215363358f12687100710caff0e86cd9d26b
// Weiszfeld's algorithm

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        static const double EPS = 1e-6;
        pair<double, double> median;
        median.first = (accumulate(cbegin(positions), cend(positions), 0.0,
                                   [](const auto& a, const auto& b) {
                                       return a + b[0];
                                   }) / positions.size());
        median.second = (accumulate(cbegin(positions), cend(positions), 0.0,
                                    [](const auto& a, const auto& b) {
                                        return a + b[1];
                                    }) / positions.size());
        pair<double, double> prev_median = {-1.0, -1.0};
        while (prev_median.first < 0 || norm(median, prev_median) * positions.size() > EPS) {
            const auto& [stopped, new_median] = geometry_median(positions, median);
            if (stopped) {
                break;
            }
            prev_median = median;
            median = new_median;
        }
        return accumulate(cbegin(positions), cend(positions), 0.0,
                          [this, &median](const auto& a, const auto& b) {
                              return a + norm(median, pair(b[0], b[1]));
                          });
    }

private:
    double norm(const pair<double, double>& p1,
                const pair<double, double>& p2) {
        return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                    (p1.second - p2.second) * (p1.second - p2.second));
    }
        
    pair<bool, pair<double, double>> geometry_median(
        const vector<vector<int>>& positions,
        const pair<double, double>& median) {
        pair<double, double> numerator = {0.0, 0.0};
        double denominator = 0.0;
        for (const auto& p : positions) {
            const auto& l = norm(median, pair(p[0], p[1]));
            if (!l) {
                continue;
            }
            numerator.first += p[0] / l;
            numerator.second += p[1] / l;
            denominator += 1 / l;
        }
        if (denominator == 0.0) {
            return {true, {0.0, 0.0}}; 
        }
        return {false, {numerator.first / denominator, numerator.second / denominator}};
    }
};
