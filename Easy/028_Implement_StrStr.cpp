using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        /* Brute force */
        /* m: number of nodes in haystack */
        /* n: number of nodes in needle */
        /* Time: O(mn), space: O(1) */
        /* Runtime: 6ms */
        int i, j, m = haystack.length(), n = needle.length();
        for (i = 0; i < m - n + 1; i++) {
            for (j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == n) return i;
        }
        return -1;
    }

    /* Advanced solution: KMP algorithm */
};
