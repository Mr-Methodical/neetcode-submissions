class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // the first row and first column will tell us if we need to update
        // the entire row to zero or not
        int rows = matrix.size();
        int cols = matrix[0].size();
        // we have to do the first row ourselves
        bool zero_col = false;
        bool zero_row = false;
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                zero_row = true;
            }
        }
        for (int j = 0; j < cols; ++j) {
            if (matrix[0][j] == 0) {
                zero_col = true;
            }
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    // set both to 0
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (zero_col) {
            for (int i = 0; i < cols; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (zero_row) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
