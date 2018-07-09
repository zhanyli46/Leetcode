#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Time: O(n^2 * s), space: O(1) (not considering stack space)
        // Runtime: 4ms
        int m = board.size();
        int n = m > 0 ? board[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (existFrom(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    bool existFrom(vector<vector<char>>& board, string word, int index, int r, int c) {
        int m = board.size();
        int n = m > 0 ? board[0].size() : 0;
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        char ch = board[r][c];
        if (index == word.length() - 1 && ch == word[index]) return true;
        if (ch != word[index]) return false;
        board[r][c] = '\0';
        bool exists = existFrom(board, word, index + 1, r, c + 1) ||
                      existFrom(board, word, index + 1, r, c - 1) ||
                      existFrom(board, word, index + 1, r + 1, c) ||
                      existFrom(board, word, index + 1, r - 1, c);
        board[r][c] = ch;
        return exists;
    }
};
