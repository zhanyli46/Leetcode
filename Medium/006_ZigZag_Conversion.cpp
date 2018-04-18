class Solution {
public:
    string convert(string s, int numRows) {
        /* Math solution */
        /* Time: O(n), space: O(1) */
        /* Runtime: 38ms */
        if (numRows < 2) return s;
        int i, j, n = s.length(), step_size = 2 * numRows - 2;
        string zigzag;
        for (i = 0; i < numRows; i++) {
            for (j = i; j < n; j += step_size) {
                zigzag += s[j];
                if (i != 0 && i != numRows - 1 && (j + step_size - 2 * i < n))
                    zigzag += s[j + step_size - 2 * i];
            }
        }
        return zigzag;
    }
};
