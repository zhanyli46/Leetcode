using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // store and check
        // Time: O(n), space: O(n)
        // Runtime: 39ms
        int char_num[26] = {0}; // use register keyword here to gain speed
        for (int i = 0; i < s.length(); ++i) {
            ++char_num[s[i] - 'a'];
        }
        for (int i = 0; i < s.length(); ++i) {
            if (char_num[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
