using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 5ms */
        int i = s.length() - 1;
        int left = 0, right = 0;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        right = i;
        while (i >= 0 && s[i] != ' ') {
            i--;
        }
        left = i;
        return right - left;
    }
};
