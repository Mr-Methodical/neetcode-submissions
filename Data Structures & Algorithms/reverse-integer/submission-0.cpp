class Solution {
public:
    int reverse(int x) {
        string curr = to_string(abs(x));
        std::reverse(curr.begin(), curr.end());
        long num = stol(curr);
        num = (x < 0) ? -num : num;
        if (pow(-2, 31) > num || num > pow(2, 31) - 1) return 0;
        return (int)num;
    }
};
