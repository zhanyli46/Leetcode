class Solution {
public:
    int hammingDistance(int x, int y) {
        // Time: O(1), space: O(1)
        // Runtime: 0ms
        int count = 0;
        for (int mask = 1; mask != 0; mask <<= 1) {
            if ((x & mask) != (y & mask))
                ++count;
        }
        return count;
    }

    int hammingDistance(int x, int y) {
        // Brian Kernighan's bit counting
        // Time: O(1), space: O(1)
        // Runtime: 0ms
        int count = 0, n = x ^ y;
        while (n) {
            ++count;
            n &= n - 1;
        }
        return count;
    }
};
