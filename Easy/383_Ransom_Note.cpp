#include <unordered_map>
#include <algorithm>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        /* Hashmap */
        /* Time: O(m + n), space: O(n) */
        /* Runtime: 35ms */
        if (ransomNote.empty()) return true;
        if (magazine.empty()) return false;
        unordered_map<char, int> dict;
        int m = ransomNote.length(), n = magazine.length();
        for (int i = 0; i < n; ++i)
            ++dict[magazine[i]];
        for (int i = 0; i < m; ++i) {
            if (dict.find(ransomNote[i]) == dict.end() || dict[ransomNote[i]] == 0)
                return false;
            else
                --dict[ransomNote[i]];
        }
        return true;
    }

    bool canConstruct(string ransomNote, string magazine) {
        /* Sort + 2 pointers */
        /* Time: O(nlogn), space: O(1) */
        /* Runtime: 50ms */
        if (ransomNote.empty()) return true;
        if (magazine.empty()) return false;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int m = ransomNote.length(), n = magazine.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (ransomNote[i] < magazine[j])
                return false;
            else if (ransomNote[i] > magazine[j])
                ++j;
            else
                ++i, ++j;
        }
        return i == m;
    }

    bool canConstruct(string ransomNote, string magazine) {
        /* Constant buffer dict */
        /* Time: O(m + n), space: O(1) */
        /* Runtime: 35ms */
        int m = ransomNote.length(), n = magazine.length();
        int dict[26] = {0};
        for (int i = 0; i < n; ++i)
            ++dict[magazine[i] - 'a'];
        for (int i = 0; i < m; ++i) {
            if (dict[ransomNote[i] - 'a'] == 0)
                return false;
            else
                --dict[ransomNote[i] - 'a'];
        }
        return true;
    }
};
