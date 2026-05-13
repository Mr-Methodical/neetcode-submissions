class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                int total = 0;
                if (tokens[i] == "+") {
                    total = op1 + op2;
                } else if (tokens[i] == "-") {
                    total = op1 - op2;
                } else if (tokens[i] == "*") {
                    total = op1 * op2;
                } else {
                    total = op1 / op2;
                }
                s.push(total);
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
