#include <cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        // Iterative method
        // Time: O(sqrt(n)), space: O(1)
        // Runtime: 20ms
        int width = 1;
        int count = 0;
        while (n >= width) {
            n -= width;
            ++width;
            ++count;
        }
        return count;
    }
    int arrangeCoins(int n) {
        // Mathematical method
        // Time: O(log(n)), space: O(1)
        // Runtime: 16ms
        return (int)(sqrt(8.0 * n + 1) - 1) / 2;
    }
};
