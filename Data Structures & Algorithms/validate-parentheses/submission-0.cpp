class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                paren.push(s[i]);
            } else {
                // it is one of those outer character
                char c = '[';
                if (s[i] == '}') c = '{';
                if (s[i] == ')') c = '(';
                if (paren.empty() || paren.top() != c) return false;
                else paren.pop();
            }
        }
        if (!paren.empty()) return false;
        return true;
    }
};
