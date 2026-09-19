class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(n * m);
        // keep going right until we hit end or -1
        int i = 0;
        int j = 0;
        int c = 0;
        v[c++] = matrix[0][0];
        matrix[0][0] = -101;
        while (true) {
            bool made_move = false;
            while (j + 1 != m && matrix[i][j + 1] != -101) {
                // made sure the next one is safe
                made_move = true;
                ++j;
                v[c++] = matrix[i][j];
                matrix[i][j] = -101;
            }
            while (i + 1 != n && matrix[i + 1][j] != -101) {
                // made sure the next one is safe
                made_move = true;
                ++i;
                v[c++] = matrix[i][j];
                matrix[i][j] = -101;
            }
            while (j - 1 != -1 && matrix[i][j - 1] != -101) {
                // made sure the next one is safe
                made_move = true;
                --j;
                v[c++] = matrix[i][j];
                matrix[i][j] = -101;
            }
            while (i - 1 != -1 && matrix[i - 1][j] != -101) {
                // made sure the next one is safe
                made_move = true;
                --i;
                v[c++] = matrix[i][j];
                matrix[i][j] = -101;
            }
            if (!made_move) break;
        }
        return v;
    }
};
