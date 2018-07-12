#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        // Time: O(n), space: O(1)
        // Runtime: 4ms
        int n = chars.size();
        if (n <= 1) return n;
        char ch = chars[0];
        int i = 0, start = 0, p = 0;
        while (i < n) {
            while (i < n && chars[i] == ch) ++i;
            if (i - start == 1) {
                chars[p++] = ch;
            } else {
                chars[p++] = ch;
                string ch_count = to_string(i - start);
                for (int j = 0; j < ch_count.length(); ++j)
                    chars[p++] = ch_count[j];
            }
            start = i;
            ch = chars[i];
        }
        chars.resize(p);
        return p;
    }
};
