class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // we need to know how to identify when something
        uint32_t result = 0; 
        for (uint32_t i = 0; i < 32; ++i) {
            // what is at the ith bit of the input is it a one or a zero and we need that
            uint32_t curr = n & (1 << i);
            // now curr is already shifted left by i
            // now we need to know how to set something
            result = result | ((curr >> i) << (31 - i));
        }
        return result;
    }
};
