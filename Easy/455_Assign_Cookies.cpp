#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Time: O(nlogn), space: O(1)
        // Runtime: 28ms
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                ++i, ++j;
            } else {
                ++j;
            }
        }
        return i;
    }
};
