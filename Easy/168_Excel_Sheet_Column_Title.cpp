using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        /* Time: O(log_26(n)), space: O(1) */
        /* Runtime: 2ms */
        string title;
        char c;
        while (n != 0) {
            c = (n - 1) % 26 + 'A';
            title = c + title;
            n = (n - 1) / 26;
        }
        return title;
    }
};
