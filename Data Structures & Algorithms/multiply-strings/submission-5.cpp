class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int s1 = num1.size();
        int s2 = num2.size();
        vector<int> res(s1 + s2, 0);
        for (int i = 0; i < s2; ++i) {
            for (int j = 0; j < s1; ++j) {
                int prod = (num1[j] - '0') * (num2[i] - '0');
                res[i + j] += prod % 10;
                if (res[i + j] > 9) {
                    res[i + j] -= 10;
                    res[i + j + 1]++;
                }
                res[i + j + 1] += prod / 10;
                if (res[i + j + 1] > 9) {
                    res[i + j + 1] -= 10;
                    res[i + j + 2]++;
                }
            }
        }
        reverse(res.begin(), res.end());
        string result = "";
        if (res[0]) {
            result.push_back(res[0] + '0');
        }
        for (int i = 1; i < res.size(); ++i) {
            result.push_back(res[i] + '0');
        }
        return result;
    }
};
