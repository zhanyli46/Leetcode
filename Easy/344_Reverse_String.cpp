#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 10ms */
        string rev = s;
        int i = 0, j = rev.length() - 1;
        while (i < j) {
            swap(rev[i++], rev[j--]);
        }
        return rev;
    }
};
