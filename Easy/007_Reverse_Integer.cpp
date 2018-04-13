#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 31ms */
        int rev_x = 0;
        int temp;
        while (x != 0) {
            temp = rev_x * 10 + x % 10;
            if (temp / 10 != rev_x)
                return 0;
            rev_x = temp;
            x /= 10;
        }
        return rev_x;
    }
};
