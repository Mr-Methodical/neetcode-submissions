class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / myPow(x, -1 * n);
        if (n == 0) return 1.0;
        // we now know n is greater than 0 integer
        if (n % 2 == 0) return myPow(x * x, n / 2);
        return x * myPow(x * x, n / 2);
    }
};
