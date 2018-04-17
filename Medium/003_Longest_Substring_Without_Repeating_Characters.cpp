#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* Two Pointers */
        /* Time O(n), space O(n) */
        /* Runtime: 47ms */
        unordered_set<char> charset;
        int i = 0, j = 0, n = s.length(), max_len = 0;
        while (i < n && j < n) {
            if (charset.count(s[j]) > 0) {
                charset.erase(s[i]);
                i++;
            } else {
                charset.insert(s[j]);
                j++;
                max_len = max(max_len, j - i);
            }
        }
        return max_len;
    }
};
