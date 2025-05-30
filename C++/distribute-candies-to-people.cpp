// Time:  O(n + logc), c is the number of candies
// Space: O(1)

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        // find max integer p s.t. sum(1 + 2 + ... + p) <= C
        // => remaining : 0 <= C-(1+p)*p/2 < p+1
        // => -2p-2 < p^2+p-2C <= 0
        // => 2C+1/4 < (p+3/2)^2 and (p+1/2)^2 <= 2C+1/4
        // => sqrt(2C+1/4)-3/2 < p <= sqrt(2C+1/4)-1/2
        // => p = floor(sqrt(2C+1/4)-1/2)
        int p = int(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = candies - (p + 1) * p / 2;
        int rows = p / num_people, cols = p % num_people;
            
        vector<int> result(num_people);
        for (int i = 0; i < num_people; ++i) {
            result[i] = (i < cols) ? (i + 1) * (rows + 1) + (rows * (rows + 1) / 2) * num_people
                                   : (i + 1) * rows + ((rows - 1) * rows / 2) * num_people;
        }
        result[cols] += remaining;
        return result;
    }
};
