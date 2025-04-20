// Time:  +:        O(d * t), t is the number of terms, d is the average degree of terms
//        -:        O(d * t)
//        *:        O(d * t^2)
//        eval:     O(d * t)
//        to_list:  O(d * tlogt)
// Space: O(e + d * t), e is the number of evalvars

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> lookup;
        for (int i = 0; i < evalvars.size(); ++i) {
            lookup[evalvars[i]] = evalints[i];
        }
        return parse(expression).eval(lookup);
    }

private:
    Poly parse(const string& s) {
        static const unordered_map<char, int> precedence = {{'+', 0}, {'-', 0}, {'*', 1}};

        stack<Poly> operands;
        stack<char> operators;
        string operand;
        for (int i = 0; i < size(s); ++i) {
            if (isalnum(s[i])) {
                operand.push_back(s[i]);
                if (i + 1 == size(s) || !isalnum(s[i + 1])) {
                    operands.emplace(Poly(operand));
                    operand = "";
                }
            } else if (s[i] == '(') {
                operators.emplace(s[i]);
            } else if (s[i] == ')') {
                while (operators.top() != '(') {
                    compute(&operands, &operators);
                }
                operators.pop();
            } else if (precedence.count(s[i])) {
                while (!empty(operators) && precedence.count(operators.top()) && 
                       precedence.at(operators.top()) >= precedence.at(s[i])) {
                     compute(&operands, &operators);
                }
                operators.emplace(s[i]);
            }
        }
        while (!empty(operators)) {
            compute(&operands, &operators);
        }
        return operands.top();
    }

    template<typename T>
    void compute(stack<T> *operands, stack<char> *operators) {
        const auto right = move(operands->top()); operands->pop();
        const auto left = move(operands->top()); operands->pop();
        const char op = operators->top(); operators->pop();
        if (op == '+') {
            operands->emplace(left + right);
        } else if (op == '-') {
            operands->emplace(left - right);
        } else if (op == '*') {
            operands->emplace(left * right);
        }
    }
};
