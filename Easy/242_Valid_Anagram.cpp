#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        /* ASCII only */
        /* Time: O(n), space: O(1) */
        /* Runtime: 12ms */
        if (s.length() != t.length()) return false;
        int n = s.length();
        int count[256] = {0};
        for (int i = 0; i < n; ++i) {
            ++count[s[i]];
            --count[t[i]];
        }
        for (int i = 0; i < 256; ++i) {
            if (count[i] != 0) return false;
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        /* Unicode */
        /* Time: O(n), space: O(n) */
        /* Runtime: 23ms */
        unordered_map<char, int> char_map;
        for (int i = 0; i < s.length(); ++i) {
            if (char_map.find(s[i]) == char_map.end())
                char_map.insert({s[i], 1});
            else
                ++char_map[s[i]];
        }
        for (int i = 0; i < t.length(); ++i) {
            if (char_map.find(t[i]) == char_map.end())
                return false;
            else
                --char_map[t[i]];
        }
        for (auto pair : char_map) {
            if (pair.second != 0) return false;
        }
        return true;
    }
};
