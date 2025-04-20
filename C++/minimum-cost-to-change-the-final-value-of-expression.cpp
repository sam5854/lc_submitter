// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minOperationsToFlip(string expression) {
        static const unordered_map<char, int> precedence = {{'&', 0}, {'|', 0}};

        vector<vector<int>> operands;
        vector<char> operators;
        for (const auto& c : expression) {
            if (isdigit(c)) {
                operands.push_back({int(c != '0'), int(c != '1')});
            } else if (c == '(') {
                operators.emplace_back(c);
            } else if (c == ')') {
                while (operators.back() != '(') {
                    compute(&operands, &operators);
                }
                operators.pop_back();
            } else if (precedence.count(c)) {
                while (!empty(operators) && precedence.count(operators.back()) && 
                       precedence.at(operators.back()) >= precedence.at(c)) {
                     compute(&operands, &operators);
                }
                operators.emplace_back(c);
            }
        }
        while (!empty(operators)) {
            compute(&operands, &operators);
        }
        return *max_element(cbegin(operands.back()), cend(operands.back()));
    }

private:
    template<typename T>
    void compute(vector<T> *operands, vector<char> *operators) {
        const auto right = operands->back(); operands->pop_back();
        const auto left = operands->back(); operands->pop_back();
        const char op = operators->back(); operators->pop_back();
        if (op == '&') {
            operands->push_back({min(left[0], right[0]), min(left[1] + right[1], min(left[1], right[1]) + 1)});
        } else if (op == '|') {
            operands->push_back({min(left[0] + right[0], min(left[0], right[0]) + 1), min(left[1], right[1])});
        }
    }
};
