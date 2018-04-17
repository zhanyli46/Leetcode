using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 7ms */
        int i, n = s.length(), num = 0;
        for (i = 0; i < n; i++) {
            num = 26 * num + (s[i] - 'A' + 1);
        }
        return num;
    }
};
