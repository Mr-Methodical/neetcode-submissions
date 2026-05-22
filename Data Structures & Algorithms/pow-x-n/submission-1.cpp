class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / myPow(x, -1 * n);
        if (n == 0) return 1.0;
        // so n can only be positive now
        double result = x;
        for (int i = 1; i < n; ++i) {
            result *= x;
        }
        return result;
    }
};
