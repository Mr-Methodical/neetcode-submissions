class Solution {
public:
    string arr[10];
    void backtrack(vector<string>& result, string& digits, string& curr, int idx) {
        if (idx == digits.size()) {
            result.push_back(curr);
            return;
        }
        for (char c : arr[digits[idx] - '0']) {
            curr += c;
            backtrack(result, digits, curr, idx + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        arr[2] = "abc";
        arr[3] = "def";
        arr[4] = "ghi";
        arr[5] = "jkl";
        arr[6] = "mno";
        arr[7] = "pqrs";
        arr[8] = "tuv";
        arr[9] = "wxyz";
        vector<string> result;
        string curr;
        backtrack(result, digits, curr, 0);
        return result;
    }
};
