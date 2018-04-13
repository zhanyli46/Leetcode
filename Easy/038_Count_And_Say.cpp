using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        /* Time: ?, space: O(1) */
        /* Runtime: 4ms */
        string s = "1";
        int i, count;
        char ch = s[0];
        while (n-- > 1) {
            string next = "";
            for (i = 0; i < s.length(); i++) {
                count = 1;
                while ((i < s.length() - 1) && (s[i] == s[i + 1])) {
                    count++;
                    i++;
                }
                next += to_string(count) + s[i];
            }
            s = next;
        }
        return s;
    }
};
