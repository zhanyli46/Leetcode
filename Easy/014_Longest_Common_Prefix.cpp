#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix_1(vector<string>& strs) {
        /* Brute force */
        /* m: length of string */
        /* n: number of strings in array */
        /* Time: O(mn), space: O(1) */
        /* Runtime: 10ms */
        int i = 0, m = 0, n = strs.size();
        string prefix;
        char ch;
        if (n == 0) return prefix;
        while (m < strs[i].length()) {
            if (i == n) {
                prefix += ch;
                i = 0;
                m++;
            } else if (i == 0) {
                ch = strs[i++][m];
            } else {
                if (strs[i++][m] != ch)
                    break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix_2(vector<string>& strs) {
        /* Sorting and comparing */
        /* m: length of string */
        /* n: number of strings in array */
        /* Time: O(m + n log n), space: O(1) */
        /* Runtime: 14ms */
        int m, n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        sort(strs.begin(), strs.end());
        for (m = 0; m < strs[0].length(); m++) {
            if (strs[0][m] != strs[n - 1][m])
                break;
        }
        return strs[0].substr(0, m);
    }
};
