class Solution {
public:
    int uniquePaths(int m, int n) {
        // we can also do it with math:
        // we have to go down m - 1 and right n - 1 so m + n - 2 moves
        // then we have a sequence of options where we can either choose D or R
        // we have to choose D m - 1times and the order is not unique, so order doesn't matter
        // so this is just m + n - 2 choose m - 1 times
        long long result = 1;
        for (int i = 1; i <= m - 1; i++) {
            result *= (m + n - 2 - i + 1); // the + 1 is for the fact i should start at 0
            result /= i;
        }
        return (int)result;
    }
};
