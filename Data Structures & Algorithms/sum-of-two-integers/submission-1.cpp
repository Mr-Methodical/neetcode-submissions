class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            // carry will be all the 1's that come over
            int carry = (a & b) << 1;
            // XOR it to basically get the sum but we don't want to double count the carry
            // a should be that sum betweent the two not counting the carry and then b will get to 0 eventually and a will be right
            a = a ^ b;
            // b is what we have to add to it next time
            b = carry;
        }
        return a;
    }
};
