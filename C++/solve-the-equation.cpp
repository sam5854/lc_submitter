// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string solveEquation(string equation) {
        auto a = 0, b = 0;
        auto side = 1;
        int submatches[] = { 1, 2, 3, 4 };
        auto e = regex("(=)|([-+]?)(\\d*)(x?)");
        for (regex_token_iterator<string::iterator> it(equation.begin(), equation.end(), e, submatches), end;
             it != end;) {
            auto eq = (it++)->str();
            auto sign = (it++)->str();
            auto num = (it++)->str();
            auto isx = (it++)->str();
            if (!eq.empty()) {
                side = -1;
            } else if (!isx.empty()) {
                a += side * stoi(sign + "1") * stoi(num.empty() ? "1" : num);
            } else if (!num.empty()) {
                b -= side * stoi(sign + num);
            }
        }
        return a != 0 ? "x=" + to_string(b / a) : b != 0 ? "No solution" : "Infinite solutions";
    }
};
