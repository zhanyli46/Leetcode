#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 303ms */
        string str_x = to_string(x);
        int i = 0, j = str_x.length() - 1;
        while (i < j) {
            if (str_x[i++] != str_x[j--])
                return false;
        }
        return true;
    }
};
