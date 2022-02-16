class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t bit = 0;
        
        for (int i = 0; i < 32; i++, n >>= 1) {
            bit = bit<<1 | n&1;
            n>>1;
        }
        
        return bit;
    }
};