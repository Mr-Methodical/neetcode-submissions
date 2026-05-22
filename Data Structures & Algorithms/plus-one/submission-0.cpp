class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Let's go with the carry approach
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            int keep = sum % 10;
            carry = sum / 10;
            digits[i] = keep;
        }
        vector<int> retval;
        if (carry) {
            // we still need to add 1 to the front
            retval.push_back(1);
        }
        for (int dig : digits) {
            retval.push_back(dig);
        }
        return retval;
    }
};
