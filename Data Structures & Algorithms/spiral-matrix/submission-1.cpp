class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> v(rows * cols);
        int c = 0;
        int left = 0;
        int right = cols - 1;
        int up = 0;
        int bottom = rows - 1;
        while (left <= right and up <= bottom) {
            for (int j = left; j <= right; ++j) {
                v[c++] = matrix[up][j];
            }
            up++;
            for (int i = up; i <= bottom; ++i) {
                v[c++] = matrix[i][right];
            }
            right--;
            if (up > bottom) break;
            for (int j = right; j >= left; --j) {
                v[c++] = matrix[bottom][j];
            }
            bottom--;
            if (left > right) break;
            for (int i = bottom; i >= up; --i) {
                v[c++] = matrix[i][left];
            }
            left++;
        }
        return v;
    }
};
