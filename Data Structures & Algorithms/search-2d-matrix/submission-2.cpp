class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we can do a binary search two different ways
        // we first need to find which row it is in
        int l = 0;
        int r = matrix.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2; // so it favors the right side middle 
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                r = mid - 1; // must be lower as that was the first element
            } else {
                l = mid; // in the case that matrix[mid][0] is lower mid might actually be right
            }
        }
        // r is going to be in the row that is less than or equal to all the values
        int lc = 0;
        int rc = matrix[l].size() - 1;
        while (lc <= rc) {
            int mid = lc + (rc - lc) / 2;
            if (matrix[l][mid] == target) {
                return true;
            } else if (matrix[l][mid] < target) {
                lc = mid + 1;
            } else {
                rc = mid - 1;
            }
        }
        return false;
    }
};
