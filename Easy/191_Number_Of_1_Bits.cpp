class Solution {
public:
    int hammingWeight(uint32_t n) {
        /* Shifting and counting */
        /* Time: O(sizeof(uint32_t)), space: O(1) */
        /* Runtime: 6ms */
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    int hammingWeight(uint32_t n) {
        /* Bit manipulation */
        /* Time: O(log_2(sizeof(uint32_t))), space: O(1) */
        /* Runtime: 6ms */
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }
};
