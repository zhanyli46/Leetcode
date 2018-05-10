#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /* Time: O(n^2)?, space: O(1) */
        /* Runtime: 3ms */
        if (n == 0) return {""};
        vector<string> v;
        recursiveGenerate(n, n, v, "");
        return v;
    }

private:
    void recursiveGenerate(int l, int r, vector<string> &v, string par) {
        if (r < l) return;
        if (l == 0 && r == 0) v.push_back(par);
        if (l > 0) recursiveGenerate(l - 1, r, v, par + "(");
        if (r > 0) recursiveGenerate(l, r - 1, v, par + ")");
    }
};
