// Time:  O(k^n)
// Space: O(k^n)
// https://en.wikipedia.org/wiki/De_Bruijn_sequence
// https://en.wikipedia.org/wiki/Lyndon_word

class Solution {
public:
    string crackSafe(int n, int k) {
        const int M = pow(k, n - 1);
        vector<int> P;
        for (int i = 0; i < k; ++i) {
            for (int q = 0; q < M; ++q) {
                P.emplace_back(q * k + i);  // rotate: i*k^(n-1) + q => q*k + i
            }
        }
        const int total = pow(k, n);
        string result(n - 1, '0' + k - 1);
        for (int i = 0; i < total; ++i) {
            int j = i;
            // concatenation in lexicographic order of Lyndon words
            while (P[j] >= 0) {
                result.push_back('0' + j / M);
                auto Pj = P[j];
                P[j] = -1;
                j = Pj;
            }
        }
        return result;
    }
};
