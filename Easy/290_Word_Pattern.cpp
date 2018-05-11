#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 2ms */
        unordered_map<char, int> pmap;
        unordered_map<string, int> smap;
        vector<string> strv;
        int i = 0, j = 0, n = str.length();
        while (j < n) {
            while (j < n && str[j] != ' ') ++j;
            strv.push_back(str.substr(i, j - i));
            i = ++j;
        }
        if (pattern.length() != strv.size())
            return false;
        for (int i = 0; i < pattern.length(); ++i) {
            auto pit = pmap.find(pattern[i]);
            auto sit = smap.find(strv[i]);
            if (pit == pmap.end())
                pmap[pattern[i]] = i;
            if (sit == smap.end())
                smap[strv[i]] = i;
            if (pmap[pattern[i]] != smap[strv[i]])
                return false;
        }
        return true;
    }
};
