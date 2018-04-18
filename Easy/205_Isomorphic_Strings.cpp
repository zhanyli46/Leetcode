#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /* Hashmap + Hashset */
        /* Time:O(n), space: O(n) */
        /* Runtime: 11ms */
        unordered_map<char, char> map;
        unordered_set<char> set;
        int i, n = s.length();
        for (i = 0; i < n; i++) {
            if (map.find(s[i]) == map.end()) {
                if (set.count(t[i]) != 0) return false;
                map.insert({s[i], t[i]});
                set.insert(t[i]);
            } else {
                if (map[s[i]] != t[i]) return false;
            }
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        /* Transform and compare */
        /* Time:O(n), space: O(1) */
        /* Runtime: 6ms */
        char mapping[128] = {'\0'};
        bool mapped[128] = {false};
        int i, n = s.length();
        for (i = 0; i < n; i++) {
            if (mapping[s[i]] == '\0' && !mapped[t[i]]) {
                mapping[s[i]] = t[i];
                mapped[t[i]] = true;
            }
            s[i] = mapping[s[i]];
        }
        return s == t;
    }
};
