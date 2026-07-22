class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> col(m, 1);
        // there is 1 way to get to the trophy as you can only go down
        for (int i = 0; i < n - 1; ++i) {
            for (int j = m - 2; j >= 0; --j) {
                // we go through the array from bottom to top
                // m - 2 because the bottom will always be 1 as you can only go right to get to the trophy
                col[j] = col[j + 1] + col[j];
            }
        }
        return col[0];
    }
};
