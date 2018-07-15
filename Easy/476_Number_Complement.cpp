class Solution {
public:
    int findComplement(int num) {
        // Time: O(1), space: O(1)
        // Runtime: 0ms
        int mask = 1;
        while (mask < num)
            mask = (mask << 1) | 0x1;
        return num ^ mask;
    }
};
