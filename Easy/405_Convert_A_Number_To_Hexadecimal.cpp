#include <algorithm>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        // Time: O(1), space: O(1)
        // Runtime: 0ms
        string hex;
        unsigned u = (unsigned)num;
        char hex_map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        while (u != 0) {
            hex += hex_map[u & 0xf];
            u >>= 4;
        }
        reverse(hex.begin(), hex.end());
        return hex.length() ? hex : "0";
    }
};
