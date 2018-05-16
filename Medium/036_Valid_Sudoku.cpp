#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 23ms */
        vector<string> rows(9, ".........");
        vector<string> cols(9, ".........");
        vector<string> squares(9, ".........");
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') continue;
                if (rows[r][ch - '1'] == '.')
                    rows[r][ch - '1'] = ch;
                else return false;
                if (cols[c][ch - '1'] == '.')
                    cols[c][ch - '1'] = ch;
                else return false;
                if (squares[r / 3 * 3 + c / 3][ch - '1'] == '.')
                    squares[r / 3 * 3 + c / 3][ch - '1'] = ch;
                else return false;
            }
        }
        return true;
    }
};
