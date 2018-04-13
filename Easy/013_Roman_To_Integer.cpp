#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 96ms */
        int result = 0, i, n = s.length();
        int m[26] = { 0 };
        m['I' - 'A'] = 1;
        m['V' - 'A'] = 5;
        m['X' - 'A'] = 10;
        m['L' - 'A'] = 50;
        m['C' - 'A'] = 100;
        m['D' - 'A'] = 500;
        m['M' - 'A'] = 1000;
        for (i = 0; i < n - 1; i++) {
            if (m[s[i] - 'A'] < m[s[i + 1] - 'A'])
                result -= m[s[i] - 'A'];
            else
                result += m[s[i] - 'A'];
        }
        return result + m[s[i] - 'A'];
    }
};
