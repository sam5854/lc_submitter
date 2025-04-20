// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool isRationalEqual(string S, string T) {
        return frac(S) == frac(T);
    }

private:
    Fraction frac(const string& S) {
        auto i = S.find('.');
        if (i == string::npos) {
            return Fraction(stol(S));
        }

        Fraction result(stol(S.substr(0, i)), 1);
        const auto& non_int_part = S.substr(i + 1);
        i = non_int_part.find('(');
        if (i == string::npos) {
            if (!non_int_part.empty()) {
                result += Fraction(stol(non_int_part),
                                   static_cast<int64_t>(pow(10, non_int_part.length())));
            }
            return result;
        }

        if (i > 0) {
            result += Fraction(stol(non_int_part.substr(0, i)),
                               static_cast<int64_t>(pow(10, i)));
        }
        const auto& repeat_part = non_int_part.substr(i + 1, non_int_part.length() - i - 2);
        result += Fraction(stol(repeat_part),
                           static_cast<int64_t>(pow(10, i)) *
                           (static_cast<int64_t>(pow(10, repeat_part.length())) - 1));
        return result;
    }   
};
