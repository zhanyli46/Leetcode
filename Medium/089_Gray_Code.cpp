#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // Time: O(n^2), space: O(1)
        // Runtime: 4ms
        // The test case states that grayCode(0) should return [0], but in my
        //  opinion, the result should be [].
        vector<int> code;
        code.push_back(0);
        if (n == 0) return code;
        code.push_back(1);
        int i = 1;
        while (i < n) {
            int l = code.size();
            for (int j = l - 1; j >= 0; --j)
                code.push_back(code[j]);
            for (int j = l; j < code.size(); ++j)
                code[j] |= 1 << i;
            ++i;
        }
        return code;
    }
};
