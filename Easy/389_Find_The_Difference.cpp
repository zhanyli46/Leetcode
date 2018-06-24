using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        // Time: O(n), space: O(1)
        // Runtime: 6ms
        int char_num[26] = {0}; // use register keyword here to gain speed
        char diff = 0;
        int i;
        for (i = 0; i < s.length(); ++i) {
            diff += t[i];
            diff -= s[i];
        }
        diff += t[i];
        return diff;
    }
};
