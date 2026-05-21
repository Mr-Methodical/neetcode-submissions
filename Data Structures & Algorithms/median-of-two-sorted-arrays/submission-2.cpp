class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2; // so left partition will have equal or more
        if (B.size() < A.size()) swap(A, B);
        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2; // like our mid
            int j = half - i; // oh because larger half for this actually
            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;
            if (Aleft <= Bright && Bleft <= Aright) {
                // then we found the correct partition
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1; // nothing will never happen
    }
};
