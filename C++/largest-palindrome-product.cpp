// Time:  O(n * 10^n)
// Space: O(n)

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        // let x = 10^n-i, y = 10^n-j, s.t. palindrome = x*y
        // => (10^n-i)*(10^n-j) = (10^n-i-j)*10^n + i*j
        // assume i*j < 10^n (in fact, it only works for 2 <= n <= 8, not general),
        // let left = (10^n-i-j), right = i*j, k = i+j
        // => left = 10^n-k, right = i*(k-i)
        // => i^2 - k*i + right = 0
        // => i = (k+(k^2-right*4)^(0.5))/2 or (k+(k^2-right*4)^(0.5))/2 where i is a positive integer
        const int upper = pow(10, n) - 1;
        for (int k = 2; k <= upper; ++k) {
            const int left = pow(10, n) - k;
            auto s = to_string(left);
            reverse(begin(s), end(s));
            const int right = stoi(s);
            const int d = k * k - right * 4;
            if (d < 0) {
                continue;
            }
            if (sqrt(d) == int(sqrt(d)) && k % 2 == int(sqrt(d)) % 2) {
                return (static_cast<uint64_t>(left * pow(10, n)) + right) % 1337;
            }
        }
        return -1;
    }

private:
    long long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoll(to_string(n) + s);
    }
};
