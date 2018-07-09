#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Sliding window
        // Time: O(sp), space: O(p)
        // Runtime: 20ms
        vector<int> sv(256, 0), pv(256, 0), match_pos;
        if (s.length() < p.length())
            return match_pos;
        for (int i = 0; i < p.length(); ++i) {
            ++sv[s[i]];
            ++pv[p[i]];
        }
        if (sv == pv) match_pos.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++sv[s[i]];
            --sv[s[i - p.size()]];
            if (sv == pv)
                match_pos.push_back(i - p.size() + 1);
        }
        return match_pos;
    }
    vector<int> findAnagrams(string s, string p) {
        // TODO: look up KMP algorithm or Rabin Karp algorithm
    }
};
